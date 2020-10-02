#include "mediamanager.hpp"




void ShowImage(const cv::Mat img)
{
    cv::namedWindow("Yolo Recognition", cv::WINDOW_AUTOSIZE);
    cv::imshow("Yolo Recognition", img);
    cv::waitKey(0);
    cv::destroyWindow("Yolo Recognition");
}
