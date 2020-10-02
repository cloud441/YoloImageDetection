#pragma once

#include <opencv2/opencv.hpp>

cv::dnn::Net LoadNetwork();

cv::Mat Blobification(const cv::Mat img);
