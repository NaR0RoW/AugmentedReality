#include <fstream>
#include <iostream>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <stdio.h>

int CHECKERBOARD[2]{5,7};

int main() {
    
    std::vector<std::vector<cv::Point3f> > objpoints;
    std::vector<std::vector<cv::Point2f> > imgpoints;
    std::vector<cv::Point3f> objp;
   
    for(int i{0}; i<CHECKERBOARD[1]; i++) {
        for(int j{0}; j<CHECKERBOARD[0]; j++)
            objp.push_back(cv::Point3f(j,i,0));
    }
    
    std::vector<cv::String> images;
    std::string path = "./images/*.jpg";
    cv::glob(path, images);
    cv::Mat frame, gray;
    std::vector<cv::Point2f> corner_pts;
    
    bool success;
    
    for(int i{0}; i<images.size(); i++) {
        frame = cv::imread(images[i]);
        cv::cvtColor(frame,gray,cv::COLOR_BGR2GRAY);
        success = cv::findChessboardCorners(gray, cv::Size(CHECKERBOARD[0], CHECKERBOARD[1]), corner_pts, cv::CALIB_CB_ADAPTIVE_THRESH | cv::CALIB_CB_FAST_CHECK | cv::CALIB_CB_NORMALIZE_IMAGE);
        
        if(success) {
            cv::TermCriteria criteria(cv::TermCriteria::EPS | cv::TermCriteria::MAX_ITER, 30, 0.001);
            cv::cornerSubPix(gray,corner_pts,cv::Size(11,11), cv::Size(-1,-1),criteria);
            cv::drawChessboardCorners(frame, cv::Size(CHECKERBOARD[0], CHECKERBOARD[1]), corner_pts, success);
            objpoints.push_back(objp);
            imgpoints.push_back(corner_pts);
        }
        
        cv::imshow("Image",frame);
        cv::waitKey(0);
    }
    
    cv::destroyAllWindows();
    cv::Mat cameraMatrix,distCoeffs,R,T;
calibrateCamera(objpoints, imgpoints, cv::Size(gray.rows,gray.cols), cameraMatrix, distCoeffs, R, T);
    std::ofstream outStream("../../../../camera");
   
    if (outStream) {
        uint16_t rows = cameraMatrix.rows;
        uint16_t cols = cameraMatrix.cols;
        outStream << rows << std::endl;
        outStream << cols << std::endl;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                double value = cameraMatrix.at<double>(r, c);
                outStream << value << " ";
            }
            
            outStream << std::endl;
        }
        
        uint16_t dist_rows = distCoeffs.rows;
        uint16_t dist_cols = distCoeffs.cols;
        outStream << dist_rows << std::endl;
        outStream << dist_cols << std::endl;
        
        for (int r = 0; r < dist_rows; r++) {
            for (int c = 0; c < dist_cols; c++) {
                double dvalue = distCoeffs.at<double>(r, c);
                outStream << dvalue << " ";
            }
            
            outStream << std::endl;
        }
        
        outStream.close();
    }
    
    std::cout << "cameraMatrix : " << cameraMatrix << std::endl;
    std::cout << "distCoeffs : " << distCoeffs << std::endl;
    std::cout << "Rotation vector : " << R << std::endl;
    std::cout << "Translation vector : " << T << std::endl;

    return 0;
}
