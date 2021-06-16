#pragma once

#include <rclcpp/node.hpp>
#include <opencv2/opencv.hpp>
#include <sensor_msgs/msg/image.hpp>

class Emitter : public rclcpp::Node {
public:
    Emitter();

private:
    void capture_once();

private:
    cv::Mat frame_;
    cv::VideoCapture capture_;
    std::shared_ptr<rclcpp::TimerBase> timer_;
    std::shared_ptr<rclcpp::Publisher<sensor_msgs::msg::Image>> publisher_;
};
