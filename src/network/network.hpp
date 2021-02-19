#pragma once

#include <opencv2/opencv.hpp>

#define WEIGHT_FILE "../data/weights/yolov3-tiny.weights"
#define CONFIG_FILE "../data/config/yolov3-tiny.cfg"
#define BLOB_SIZE 416

cv::dnn::Net LoadNetwork();

cv::Mat Blobification(const cv::Mat img);
