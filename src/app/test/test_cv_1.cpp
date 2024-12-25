#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;
    cv::Mat img = cv::Mat::zeros(300, 300, CV_8UC3);
    cv::imshow("Test Image", img);
    cv::waitKey(0);
    return 0;
}
