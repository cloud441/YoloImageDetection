#include "network.hpp"



cv::dnn::Net LoadNetwork()
{
    cv::dnn::Net net = cv::dnn::readNet("../data/weights/yolov3-tiny.weights",
                            "../data/config/yolov3-tiny.cfg", "Darknet");
    net.setPreferableBackend(cv::dnn::DNN_BACKEND_DEFAULT);
    net.setPreferableTarget(cv::dnn::DNN_TARGET_OPENCL);

    return net;
}


cv::Mat Blobification(const cv::Mat img)
{
    cv::Mat blob_img;

    cv::dnn::blobFromImage(img, blob_img, 1, cv::Size(416, 416), cv::Scalar(), true, false);

    return blob_img;
}
