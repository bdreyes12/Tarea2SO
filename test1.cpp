#include <opencv2/opencv.hpp>

int main() {
    cv::Mat image;
    image = cv::imread("./paisaje.jpg");
    cv::imshow("IMAGEN TEST", image);
    cv::waitKey(0);
    return 0;
}