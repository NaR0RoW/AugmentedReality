#include "cv_pkg/Emitter.hpp"

#include <cv_bridge/cv_bridge.h>

using namespace std::chrono_literals;

Emitter::Emitter() : rclcpp::Node{"emitter"}, capture_{0} {
    if (!capture_.isOpened()) {
        throw std::runtime_error{"capture is not opened"};
    }
    timer_ = create_wall_timer(25ms, [this] { capture_once(); });
    publisher_ = create_publisher<sensor_msgs::msg::Image>("/raw_image", 10);
}

void Emitter::capture_once() {
    capture_ >> frame_;
    //capture_.retrieve(frame_);
    if (frame_.empty()) {
        throw std::runtime_error{"frame_ is empty"};
    }

    publisher_->publish(*cv_bridge::CvImage{std_msgs::msg::Header{}, "bgr8", frame_}.toImageMsg());
}
