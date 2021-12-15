#pragma once

#include <opencv2/opencv.hpp>

#define WEIGHT_FILE "../data/weights/yolov3-tiny.weights"
#define CONFIG_FILE "../data/config/yolov3-tiny.cfg"
//#define WEIGHT_FILE "../data/weights/yolo-obj_5600.weights"
//#define CONFIG_FILE "../data/config/yolo-obj.cfg"
#define BLOB_SIZE 416

cv::dnn::Net LoadNetwork();

cv::Mat Blobification(const cv::Mat img);
