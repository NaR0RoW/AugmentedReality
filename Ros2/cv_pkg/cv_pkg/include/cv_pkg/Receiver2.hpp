#pragma once

#include <rclcpp/node.hpp>
#include <opencv2/opencv.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <cv_pkg_msgs/msg/aruco_markers.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <std_msgs/msg/int32_multi_array.hpp>




class Receiver2 : public rclcpp::Node {
public:

    Receiver2();

    std::shared_ptr<cv_bridge::CvImage> image;

private:
    void drawsmth(
            cv::InputOutputArray image, cv::Mat cameraMatrix,
            cv::Mat distCoeffs, cv::Vec3d rvec, cv::Vec3d tvec,
            float l
    );
    void drawpyr(
            cv::InputOutputArray image, cv::Mat cameraMatrix,
            cv::Mat distCoeffs, cv::Vec3d rvec, cv::Vec3d tvec,
            float l
    );
    void drawHouse(
            cv::InputOutputArray image, cv::Mat cameraMatrix,
            cv::Mat distCoeffs, cv::Vec3d rvec, cv::Vec3d tvec,
            float l
    );
    void drawCubeWireframe(
            cv::InputOutputArray image, cv::Mat cameraMatrix,
            cv::Mat distCoeffs, cv::Vec3d rvec, cv::Vec3d tvec,
            float l
    );
    int draw(cv::Mat image_copy);

    void show_image(std::shared_ptr<sensor_msgs::msg::Image> myimage);
    void show_coord(std::shared_ptr<cv_pkg_msgs::msg::ArucoMarkers> &topic_msg);
    void process2_image(std::shared_ptr<sensor_msgs::msg::Image> topic_image);
    void process_ids(std::shared_ptr<std_msgs::msg::Int32MultiArray> topic_ids);

private:
    std::vector<cv::Vec3d> rvecs;
    std::vector<cv::Vec3d> tvecs;
    cv::Mat distCoeffs_;
    cv::Mat cameraMatrix_;
    std::vector<int> ids_;
    std::shared_ptr<rclcpp::Subscription<std_msgs::msg::Int32MultiArray>> subscription3_;
    std::shared_ptr<rclcpp::Subscription<sensor_msgs::msg::Image>> subscription_;
    std::shared_ptr<rclcpp::Subscription<cv_pkg_msgs::msg::ArucoMarkers>> subscription2_;

};
