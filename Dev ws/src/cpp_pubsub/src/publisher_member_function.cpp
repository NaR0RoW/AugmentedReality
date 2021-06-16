// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>

#include <opencv2/highgui/highgui.hpp>

#include <iostream>

#include <fstream>


#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

int detect_markers(std::vector<cv::Vec3d> &rvecs, std::vector<cv::Vec3d> &tvecs) {
    cv::VideoCapture inputVideo;
    inputVideo.open(0);



    //read camera matrix from file
    std::ifstream inStream("camera");



    int mat_rows, mat_cols;
    inStream >> mat_rows >> mat_cols;

    cv::Mat cameraMatrix = cv::Mat::zeros(mat_rows, mat_cols, CV_64F);

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

    cv::Mat distCoeffs = cv::Mat::zeros(dist_rows, dist_cols, CV_64F);

    distCoeffs.rows = dist_rows;
    distCoeffs.cols = dist_cols;

    for (int i = 0; i < dist_rows; i++) {
        for (int j = 0; j < dist_cols; j++) {
            inStream >> distCoeffs.at<double>(i, j);
        }
    }


    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);


    while (inputVideo.grab()) {
        cv::Mat image, imageCopy;
        inputVideo.retrieve(image);
        image.copyTo(imageCopy);
        std::vector<int> ids;
        std::vector<std::vector<cv::Point2f>> corners;
        cv::aruco::detectMarkers(image, dictionary, corners, ids);
        // if at least one marker detected
        if (ids.size() > 0) {
            cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);
            cv::aruco::estimatePoseSingleMarkers(corners, 0.07, cameraMatrix, distCoeffs, rvecs, tvecs);
            // draw axis for each marker
            for(int i=0; i<(int)ids.size(); i++) {
                cv::aruco::drawAxis(imageCopy, cameraMatrix, distCoeffs, rvecs[i], tvecs[i], 0.1);
            }
            for (int i = 0; i < (int)rvecs.size(); i++) {
                std::cout << rvecs[i] << std::endl;
            }
        }
        cv::imshow("out", imageCopy);



        char key = (char) cv::waitKey(30);
        if (key == 27)
            break;
    }
    return 0;
}

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class MinimalPublisher : public rclcpp::Node
{
public:

    std::string trans(const cv::Vec3d value) {

        std::ostringstream ss;
        ss << value;
        return ss.str();
    }


    MinimalPublisher()
  : Node("minimal_publisher"), count_(0)
  {
        publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
        timer_ = this->create_wall_timer(
                500ms, std::bind(&MinimalPublisher::timer_callback, this));

  }

private:
  void timer_callback()
  {
      std::vector<cv::Vec3d> rvecs_;
      std::vector<cv::Vec3d> tvecs_;
        detect_markers(rvecs_, tvecs_);
    for(int i = 0; i < (int)rvecs_.size(); i++) {
        auto message = std_msgs::msg::String();
        message.data = trans(rvecs_[i]) + trans(tvecs_[i]) + std::to_string(count_++);
        RCLCPP_INFO(this->get_logger(), "Tvecs: '%s'", message.data.c_str());
        publisher_->publish(message);
    }
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;


};

int main(int argc, char * argv[])
{


    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();


  return 0;
}
