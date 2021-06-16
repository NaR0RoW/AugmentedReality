#include "cv_pkg/Receiver2.hpp"
#include <cv_pkg_msgs/msg/aruco_markers.hpp>

#include <iostream>
#include <opencv2/calib3d.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <std_msgs/msg/int32.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <vector>
#include <opencv2/viz.hpp>


Receiver2::Receiver2() : rclcpp::Node{"receiver2"} {

    subscription2_ = create_subscription<cv_pkg_msgs::msg::ArucoMarkers>(
            "/markers", 10,
            [this](std::shared_ptr<cv_pkg_msgs::msg::ArucoMarkers> topic_msg) {
                show_coord(topic_msg);
            });

    subscription3_ = create_subscription<std_msgs::msg::Int32MultiArray>(
            "/ids", 10,
            [this](std::shared_ptr<std_msgs::msg::Int32MultiArray> topic_ids) {
                process_ids(topic_ids);
            });

    subscription_ = create_subscription<sensor_msgs::msg::Image>(
            "/raw_image", 10,
            [this](std::shared_ptr<sensor_msgs::msg::Image> topic_image) {
                process2_image(std::move(topic_image));
            });
}

void Receiver2::drawsmth(cv::InputOutputArray image, cv::Mat cameraMatrix,
                         cv::Mat distCoeffs, cv::Vec3d rvec, cv::Vec3d tvec,
                         float l) {
    float half_l = l / 2.0;
    std::vector<cv::Point3f> axisPoints;
    // K
    axisPoints.push_back(cv::Point3f(l*0.375, l*0.375, 0));
    axisPoints.push_back(cv::Point3f(l*0.375, l*0.375, l));
    axisPoints.push_back(cv::Point3f(l*0.375, l*0.375, half_l));
    axisPoints.push_back(cv::Point3f(l*0.375, l*0.25, 0));
    axisPoints.push_back(cv::Point3f(l*0.375, l*0.25, l));
    // E
    axisPoints.push_back(cv::Point3f(l*0.375, l*0.125, 0));
    axisPoints.push_back(cv::Point3f(l*0.375, l*0.125, half_l));
    axisPoints.push_back(cv::Point3f(l*0.375, l*0.125, l));
    axisPoints.push_back(cv::Point3f(l*0.375, 0, 0));
    axisPoints.push_back(cv::Point3f(l*0.375, 0, half_l));
    axisPoints.push_back(cv::Point3f(l*0.375, 0, l));
    //K
    axisPoints.push_back(cv::Point3f(l*0.375, -l*0.125, 0));
    axisPoints.push_back(cv::Point3f(l*0.375, -l*0.125, half_l));
    axisPoints.push_back(cv::Point3f(l*0.375, -l*0.125, l));
    axisPoints.push_back(cv::Point3f(l*0.375, -l*0.250, 0));
    axisPoints.push_back(cv::Point3f(l*0.375, -l*0.250, l));



    std::vector<cv::Point2f> imagePoints;
    cv::projectPoints(axisPoints, rvec, tvec, cameraMatrix, distCoeffs, imagePoints);
    //K
    cv::line(image, imagePoints[0], imagePoints[1], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[2], imagePoints[3], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[2], imagePoints[4], cv::Scalar(255, 0, 0), 3);
    //E
    cv::line(image, imagePoints[5], imagePoints[7], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[5], imagePoints[8], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[6], imagePoints[9], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[7], imagePoints[10], cv::Scalar(255, 0, 0), 3);
    //K
    cv::line(image, imagePoints[11], imagePoints[13], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[12], imagePoints[14], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[12], imagePoints[15], cv::Scalar(255, 0, 0), 3);
}

void Receiver2::drawpyr(cv::InputOutputArray image, cv::Mat cameraMatrix,
                        cv::Mat distCoeffs, cv::Vec3d rvec, cv::Vec3d tvec,
                        float l) {
    float half_l = l / 2.0;

    std::vector<cv::Point3f> axisPoints;
    axisPoints.push_back(cv::Point3f(half_l, half_l, 0));
    axisPoints.push_back(cv::Point3f(half_l, -half_l, 0));
    axisPoints.push_back(cv::Point3f(-half_l, -half_l, 0));
    axisPoints.push_back(cv::Point3f(-half_l, half_l, 0));
    axisPoints.push_back(cv::Point3f(0, 0, l));


    std::vector<cv::Point2f> imagePoints;
    cv::projectPoints(axisPoints, rvec, tvec, cameraMatrix, distCoeffs, imagePoints);

    cv::line(image, imagePoints[0], imagePoints[1], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[0], imagePoints[3], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[0], imagePoints[4], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[1], imagePoints[2], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[1], imagePoints[4], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[2], imagePoints[3], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[2], imagePoints[4], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[3], imagePoints[4], cv::Scalar(255, 0, 0), 3);
}

void Receiver2::drawHouse(cv::InputOutputArray image, cv::Mat cameraMatrix,
                          cv::Mat distCoeffs, cv::Vec3d rvec, cv::Vec3d tvec,
                          float l) {

    float half_l = l / 2.0;
    float double_l = l * 2.0;
    float triple = l * 1.5;

    std::vector<cv::Point3f> axisPoints;
    axisPoints.push_back(cv::Point3f(half_l, half_l, l));
    axisPoints.push_back(cv::Point3f(half_l, -half_l, l));
    axisPoints.push_back(cv::Point3f(-half_l, -half_l, l));
    axisPoints.push_back(cv::Point3f(-half_l, half_l, l));
    axisPoints.push_back(cv::Point3f(half_l, half_l, 0));
    axisPoints.push_back(cv::Point3f(half_l, -half_l, 0));
    axisPoints.push_back(cv::Point3f(-half_l, -half_l, 0));
    axisPoints.push_back(cv::Point3f(-half_l, half_l, 0));
    axisPoints.push_back(cv::Point3f(0, 0, triple));
    axisPoints.push_back(cv::Point3f(half_l, l / 4.0, 0));
    axisPoints.push_back(cv::Point3f(half_l, -l / 4.0, 0));
    axisPoints.push_back(cv::Point3f(half_l, l / 4.0, half_l));
    axisPoints.push_back(cv::Point3f(half_l, -l / 4.0, half_l));



    std::vector<cv::Point2f> imagePoints;
    //imagePoints.resize(13);
    cv::projectPoints(axisPoints, rvec, tvec, cameraMatrix, distCoeffs, imagePoints);

    cv::line(image, imagePoints[0], imagePoints[1], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[0], imagePoints[3], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[0], imagePoints[4], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[1], imagePoints[2], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[1], imagePoints[5], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[2], imagePoints[3], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[2], imagePoints[6], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[3], imagePoints[7], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[4], imagePoints[5], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[4], imagePoints[7], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[5], imagePoints[6], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[6], imagePoints[7], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[0], imagePoints[8], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[1], imagePoints[8], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[2], imagePoints[8], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[3], imagePoints[8], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[9], imagePoints[11], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[11], imagePoints[12], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[12], imagePoints[10], cv::Scalar(255, 0, 0), 3);

}



void Receiver2::drawCubeWireframe(
        cv::InputOutputArray image, cv::Mat cameraMatrix,
        cv::Mat distCoeffs, cv::Vec3d rvec, cv::Vec3d tvec,
        float l
)
{
    float half_l = l / 2.0;


    std::vector<cv::Point3f> axisPoints;
    axisPoints.push_back(cv::Point3f(half_l, half_l, l));
    axisPoints.push_back(cv::Point3f(half_l, -half_l, l));
    axisPoints.push_back(cv::Point3f(-half_l, -half_l, l));
    axisPoints.push_back(cv::Point3f(-half_l, half_l, l));
    axisPoints.push_back(cv::Point3f(half_l, half_l, 0));
    axisPoints.push_back(cv::Point3f(half_l, -half_l, 0));
    axisPoints.push_back(cv::Point3f(-half_l, -half_l, 0));
    axisPoints.push_back(cv::Point3f(-half_l, half_l, 0));


    std::vector<cv::Point2f> imagePoints;
    cv::projectPoints(axisPoints, rvec, tvec, cameraMatrix, distCoeffs, imagePoints);



    cv::line(image, imagePoints[0], imagePoints[1], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[0], imagePoints[3], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[0], imagePoints[4], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[1], imagePoints[2], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[1], imagePoints[5], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[2], imagePoints[3], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[2], imagePoints[6], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[3], imagePoints[7], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[4], imagePoints[5], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[4], imagePoints[7], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[5], imagePoints[6], cv::Scalar(255, 0, 0), 3);
    cv::line(image, imagePoints[6], imagePoints[7], cv::Scalar(255, 0, 0), 3);


}

int Receiver2::draw(cv::Mat image_copy) {
    if (rvecs.size() > 0) {
        for (int i = 0; i < ids_.size(); i++) {
            if(ids_.at(i) == 25) {
                drawCubeWireframe(
                        image_copy, cameraMatrix_, distCoeffs_, rvecs[i], tvecs[i],
                        0.053
                );
            } else if(ids_.at(i) == 21) {


                drawHouse(image_copy, cameraMatrix_, distCoeffs_, rvecs[i], tvecs[i],
                          0.053);
            } else if(ids_.at(i) == 22) {
                drawpyr(image_copy, cameraMatrix_, distCoeffs_, rvecs[i], tvecs[i],
                          0.053);
            } else if(ids_.at(i) == 24) {
                drawsmth(image_copy, cameraMatrix_, distCoeffs_, rvecs[i], tvecs[i],
                         0.053);
            }
        }
    }
    cv::imshow("Pose estimation", image_copy);
    return 1;
}

void Receiver2::show_coord(std::shared_ptr<cv_pkg_msgs::msg::ArucoMarkers> &topic_msg) {

    int ids_size = topic_msg->vectors5.at(0).z;
    ids_.resize(ids_size);
    cameraMatrix_ = cv::Mat::zeros(3, 3, CV_64F);
    //cameraMatrix_.reserve(3);
    for (int i = 0; i < 3; i++) {

        cameraMatrix_.rows = 3;
        cameraMatrix_.cols = 3;

        cameraMatrix_.at<double>(i, 0) = topic_msg->vectors3.at(i).x;
        cameraMatrix_.at<double>(i, 1) = topic_msg->vectors3.at(i).y;
        cameraMatrix_.at<double>(i, 2) = topic_msg->vectors3.at(i).z;


        //std::cout << "AGGA" << cameraMatrix_.at<double>(0, 1) << "       " << std::endl;
        distCoeffs_.rows = 1;
        distCoeffs_.cols = 5;
        distCoeffs_ = cv::Mat::zeros(1, 5, CV_64F);
        //distCoeffs_.reserve(1);
        distCoeffs_.at<double>(0, 0) = topic_msg->vectors4.at(0).x;
        distCoeffs_.at<double>(0, 1) = topic_msg->vectors4.at(0).y;
        distCoeffs_.at<double>(0, 2) = topic_msg->vectors4.at(0).z;
        distCoeffs_.at<double>(0, 3) = topic_msg->vectors5.at(0).x;
        distCoeffs_.at<double>(0, 4) = topic_msg->vectors5.at(0).y;

    }

    if (topic_msg->vectors1.size()>0) {
       for (int i = 0; i < (int) topic_msg->vectors1.size(); i++) {
           rvecs.resize(topic_msg->vectors1.size());
           tvecs.resize(topic_msg->vectors2.size());
           rvecs.at(i)[0] = topic_msg->vectors1.at(i).x;
           rvecs.at(i)[1] = topic_msg->vectors1.at(i).y;
           rvecs.at(i)[2] = topic_msg->vectors1.at(i).z;
           tvecs.at(i)[0] = topic_msg->vectors2.at(i).x;
           tvecs.at(i)[1] = topic_msg->vectors2.at(i).y;
           tvecs.at(i)[2] = topic_msg->vectors2.at(i).z;

       }
   } else {
        for (int i = 0; i < 3; i++) {

            cameraMatrix_.rows = 3;
            cameraMatrix_.cols = 3;

            cameraMatrix_.at<double>(i, 0) = 0;
            cameraMatrix_.at<double>(i, 1) = 0;
            cameraMatrix_.at<double>(i, 2) = 0;

        }
        rvecs.resize(1);
        tvecs.resize(1);
        rvecs.at(0)[0] = 0;
        rvecs.at(0)[1] = 0;
        rvecs.at(0)[2] = 0;
        tvecs.at(0)[0] = 0;
        tvecs.at(0)[1] = 0;
        tvecs.at(0)[2] = 0;
    }
}

void Receiver2::show_image(std::shared_ptr<sensor_msgs::msg::Image> myimage) {
    cv::Mat frame = cv_bridge::toCvCopy(myimage)->image;
    if (frame.empty()) {
        throw std::runtime_error{"frame_ is empty"};
    }
    cv::Mat imageCopy;
    frame.copyTo(imageCopy);


    draw(imageCopy);


    //cv::imshow("receiver2", imageCopy);
}


void Receiver2::process2_image(std::shared_ptr<sensor_msgs::msg::Image> topic_image) {

    image = cv_bridge::toCvCopy(topic_image);
    show_image(std::move(topic_image));

    // markers.vectors1.push_back(rvecs.at<geometry_msgs::msg::Vector3_<std::allocator<void>>>);
}

void Receiver2::process_ids(std::shared_ptr<std_msgs::msg::Int32MultiArray> topic_ids) {
    ids_ = topic_ids->data;
}


