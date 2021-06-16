#include <rclcpp/rclcpp.hpp>

#include "cv_pkg/Receiver2.hpp"

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    auto receiver2 = std::make_shared<Receiver2>();
    rclcpp::executors::SingleThreadedExecutor executor{};
    executor.add_node(receiver2);

    while (rclcpp::ok()) {
        executor.spin_once();
        if (!receiver2->image) {
            std::this_thread::sleep_for(std::chrono::seconds{1});
            continue;
        }

        if (cv::waitKey(1) == 27) {
            break;
        }
    }
    executor.spin();

    executor.remove_node(receiver2);

    rclcpp::shutdown();

}