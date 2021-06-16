#include <opencv2/aruco.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>
#include <string>

#include "opencv2/opencv.hpp"

int main(int argc, char** argv ) {
    cv::Mat markerImage;
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    cv::aruco::drawMarker(dictionary, 22, 200, markerImage, 1);
    cv::imwrite("marker22.png", markerImage); 
    cv::aruco::drawMarker(dictionary, 21, 200, markerImage, 1);
    cv::imwrite("marker21.png", markerImage); 
    cv::aruco::drawMarker(dictionary, 20, 200, markerImage, 1);
    cv::imwrite("marker20.png", markerImage); 
    cv::aruco::drawMarker(dictionary, 19, 200, markerImage, 1);
    cv::imwrite("marker19.png", markerImage); 
    cv::aruco::drawMarker(dictionary, 18, 200, markerImage, 1);
    cv::imwrite("marker18.png", markerImage); 
    
    return 0;
}
