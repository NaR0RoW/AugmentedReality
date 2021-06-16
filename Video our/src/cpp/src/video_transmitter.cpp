#include "cpp/video_transmitter.h"
#include "cpp/video_settings.h"
#include "cpp/base_exception.h"

std::mutex mtx;

using exception::Exception;

namespace video {
Transmitter::Transmitter(const std::string &ip, uint16_t port, int device)
    : _capture(device) {
    _capture.set(cv::CAP_PROP_FPS, Settings::FPS);
    if (!_capture.isOpened()) {
        throw Exception("VideoCapture not opened");
    }
    int width = static_cast<int>(_capture.get(cv::CAP_PROP_FRAME_WIDTH));
    int height = static_cast<int>(_capture.get(cv::CAP_PROP_FRAME_HEIGHT));
    /*
    std::string api_cmd(
        "appsrc "
        "! videoconvert "
        "! video/x-raw,format=YUY2,"
        "width=" + std::to_string(width) + ","
        "height=" + std::to_string(height) + ","
        "framerate=" + std::to_string(Settings::FPS) + "/1 "
        "! jpegenc "
        "! rtpjpegpay "
        "! udpsink "
        "host=" + ip + " "
        "port=" + std::to_string(port)
    );




    _writer = cv::VideoWriter{
        api_cmd,
        0,
        Settings::FPS,
        cv::Size(width, height),
        true};
    */
    _writer = cv::VideoWriter{
        
    };
    if (!_writer.isOpened()) {
        throw Exception("VideoWriter not opened");
    }


}
void Transmitter::send() {
    _capture.read(_frame);
    _writer.write(_frame);
}
void Transmitter::send_loop() {
    while (cv::waitKey(Settings::DELAY) == -1) {
        send();
    }
}

}  // namespace video

int main() {

    video::Transmitter{"127.0.0.1", 8081, 0}.send_loop();
    return 0;

}
