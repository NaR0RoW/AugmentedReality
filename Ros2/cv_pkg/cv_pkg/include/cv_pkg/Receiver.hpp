#pragma once

#include <rclcpp/node.hpp>
#include <opencv2/opencv.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <cv_pkg_msgs/msg/aruco_markers.hpp>
#include <std_msgs/msg/int32_multi_array.hpp>
#include <vector>

class Receiver : public rclcpp::Node {
public:
    Receiver();

    std::shared_ptr<cv_bridge::CvImage> image;

private:
    void process_image(std::shared_ptr<sensor_msgs::msg::Image>  ic_image);
    int detect_markers(std::vector<cv::Vec3d> &rvecs, std::vector<cv::Vec3d> &tvecs,
                       std::shared_ptr<sensor_msgs::msg::Image> subscription, cv::Mat &cameraMatrix, cv::Mat &distCoeffs, std::vector<int> &ids);

private:
    std::vector<int> ids;
    std::shared_ptr<rclcpp::Subscription<sensor_msgs::msg::Image>> subscription_;
    std::shared_ptr<rclcpp::Publisher<cv_pkg_msgs::msg::ArucoMarkers>> publisher_;
    std::shared_ptr<rclcpp::Publisher<std_msgs::msg::Int32MultiArray>> publisher2_;

};
