#include "cv_pkg/Receiver.hpp"
#include <cv_pkg_msgs/msg/aruco_markers.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>

#include <opencv2/highgui/highgui.hpp>

#include <iostream>

#include <fstream>


int Receiver::detect_markers(std::vector<cv::Vec3d> &rvecs, std::vector<cv::Vec3d> &tvecs,
                             std::shared_ptr<sensor_msgs::msg::Image> image_, cv::Mat &cameraMatrix, cv::Mat &distCoeffs, std::vector<int> &ids) {





    //read camera matrix from file
    std::ifstream inStream("camera");



    int mat_rows, mat_cols;
    inStream >> mat_rows >> mat_cols;

    cameraMatrix = cv::Mat::zeros(mat_rows, mat_cols, CV_64F);

    cameraMatrix.rows = mat_rows;
    cameraMatrix.cols = mat_cols;


    for (int i = 0; i < mat_rows; i++) {
        for (int j = 0; j < mat_cols; j++) {

            double value;
            inStream >> value;
            cameraMatrix.at<double>(i, j) = value;
        }
    }

    uint16_t dist_rows, dist_cols;
    inStream >> dist_rows >> dist_cols;

    distCoeffs = cv::Mat::zeros(dist_rows, dist_cols, CV_64F);

    distCoeffs.rows = dist_rows;
    distCoeffs.cols = dist_cols;

    for (int i = 0; i < dist_rows; i++) {
        for (int j = 0; j < dist_cols; j++) {
            inStream >> distCoeffs.at<double>(i, j);
        }
    }
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

        cv::Mat imageCopy;
        cv::Mat frame = cv_bridge::toCvCopy(image_)->image;

    if (frame.empty()) {
        throw std::runtime_error{"frame_ is empty"};
    }

    frame.copyTo(imageCopy);
        std::vector <std::vector<cv::Point2f>> corners;
        cv::aruco::detectMarkers(frame, dictionary, corners, ids);
        // if at least one marker detected
        if (ids.size() > 0) {
            cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);
            cv::aruco::estimatePoseSingleMarkers(corners, 0.053, cameraMatrix, distCoeffs, rvecs, tvecs);
            // draw axis for each marker
            for (int i = 0; i < (int) ids.size(); i++)
                cv::aruco::drawAxis(imageCopy, cameraMatrix, distCoeffs, rvecs[i], tvecs[i], 0.1);
        }


    return 0;
}

Receiver::Receiver() : rclcpp::Node{"receiver"} {
        subscription_ = create_subscription<sensor_msgs::msg::Image>(
            "/raw_image", 10,
            [this](std::shared_ptr<sensor_msgs::msg::Image> topic_image) {
                process_image(std::move(topic_image));
            });
    publisher_ = create_publisher<cv_pkg_msgs::msg::ArucoMarkers>("/markers", 10);
//    create_subscription<cv_pkg_msgs::msg::ArucoMarkers>("/markers", 10, []);
    publisher2_ = create_publisher<std_msgs::msg::Int32MultiArray>("/ids", 10);
}





void Receiver::process_image(std::shared_ptr<sensor_msgs::msg::Image> topic_image) {

    image = cv_bridge::toCvCopy(topic_image);
    cv::Mat cameraMatrix, distCoeffs;
    std::vector<cv::Vec3d> rvecs, tvecs;

    detect_markers(rvecs, tvecs, std::move(topic_image), cameraMatrix, distCoeffs, ids);


    //std::cout << "LOLLLLLL" << cameraMatrix.at<double>(0, 0) << std::endl;
    cv_pkg_msgs::msg::ArucoMarkers markers{};
    markers.vectors1.resize(rvecs.size());
    markers.vectors2.resize(tvecs.size());
    markers.vectors3.resize(3);
    markers.vectors4.resize(1);
    markers.vectors5.resize(1);
    if (tvecs.size() > 0) {
        for (int i = 0; i < (int) rvecs.size(); i++) {
            markers.vectors1[i].set__x(rvecs.at(i)[0]);
            markers.vectors1[i].set__y(rvecs.at(i)[1]);
            markers.vectors1[i].set__z(rvecs.at(i)[2]);
            markers.vectors2[i].set__x(tvecs.at(i)[0]);
            markers.vectors2[i].set__y(tvecs.at(i)[1]);
            markers.vectors2[i].set__z(tvecs.at(i)[2]);
        }
    }
    for (int i = 0; i < 3; i++) {
        markers.vectors3[i].set__x(cameraMatrix.at<double>(i, 0));
        markers.vectors3[i].set__y(cameraMatrix.at<double>(i, 1));
        markers.vectors3[i].set__z(cameraMatrix.at<double>(i, 2));
    }
    markers.vectors4[0].set__x(distCoeffs.at<double>(0, 0));
    markers.vectors4[0].set__y(distCoeffs.at<double>(0, 1));
    markers.vectors4[0].set__z(distCoeffs.at<double>(0, 2));
    markers.vectors5[0].set__x(distCoeffs.at<double>(0, 3));
    markers.vectors5[0].set__y(distCoeffs.at<double>(0, 4));
    markers.vectors5[0].set__z(ids.size());

    std_msgs::msg::Int32MultiArray id;
    id.set__data(ids);

    //std::cout << "LOL " << distCoeffs.at<double>(0, 0) << std::endl;
    //std::cout << "LOL " << markers.vectors3[0].x << std::endl;

   // markers.vectors1.push_back(rvecs.at<geometry_msgs::msg::Vector3_<std::allocator<void>>>);

    publisher_->publish(markers);
    publisher2_->publish(id);
}
