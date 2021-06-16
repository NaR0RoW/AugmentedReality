//
// Created by kira on 5/26/20.
//

#ifndef SMACH_LIB_VIDEO_TRANSMITTER_INCLUDE_VIDEO_RECIEVER_H_
#define SMACH_LIB_VIDEO_TRANSMITTER_INCLUDE_VIDEO_RECIEVER_H_


#include <opencv2/opencv.hpp>

namespace video {
class Receiver {
 public:
    explicit Receiver(uint16_t port);
    void show();
    void show_loop();
 private:
    cv::Mat _frame;
    cv::VideoCapture _capture;
};
}  // namespace video

#endif //SMACH_LIB_VIDEO_TRANSMITTER_INCLUDE_VIDEO_RECIEVER_H_
