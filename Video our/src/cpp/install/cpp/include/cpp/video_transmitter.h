//
// Created by kira on 5/25/20.
//

#ifndef SMACH_LIB_VIDEO_TRANSMITTER_INCLUDE_VIDEO_TRANSMITTER_H_
#define SMACH_LIB_VIDEO_TRANSMITTER_INCLUDE_VIDEO_TRANSMITTER_H_

#include <opencv2/opencv.hpp>

namespace video {
class Transmitter {
 public:
    Transmitter(const std::string &ip, uint16_t port, int device);
    void send();
    void send_loop();
 private:
    cv::Mat _frame;
    cv::VideoCapture _capture;
    cv::VideoWriter _writer;
};
}  // namespace video

#endif //SMACH_LIB_VIDEO_TRANSMITTER_INCLUDE_VIDEO_TRANSMITTER_H_
