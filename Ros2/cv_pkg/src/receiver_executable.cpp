#include <rclcpp/rclcpp.hpp>

#include "cv_pkg/Receiver.hpp"

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    auto receiver = std::make_shared<Receiver>();
    rclcpp::executors::SingleThreadedExecutor executor{};
    executor.add_node(receiver);

    while (rclcpp::ok()) {
        executor.spin_once();
        if (!receiver->image) {
            std::this_thread::sleep_for(std::chrono::seconds{1});
            continue;
        }

        if (cv::waitKey(1) == 27) {
            break;
        }
    }
    executor.spin();

    executor.remove_node(receiver);

    rclcpp::shutdown();

}