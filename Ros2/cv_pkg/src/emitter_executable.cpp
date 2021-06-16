#include <rclcpp/rclcpp.hpp>

#include "cv_pkg/Emitter.hpp"

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    auto emitter = std::make_shared<Emitter>();
    rclcpp::executors::SingleThreadedExecutor executor{};
    executor.add_node(emitter);
    executor.spin();
    executor.remove_node(emitter);

    rclcpp::shutdown();
}