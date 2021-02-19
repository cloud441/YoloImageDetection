#include "network.hpp"



cv::dnn::Net LoadNetwork()
{
    cv::dnn::Net net = cv::dnn::readNet(WEIGHT_FILE, CONFIG_FILE, "Darknet");
    net.setPreferableBackend(cv::dnn::DNN_BACKEND_DEFAULT);
    net.setPreferableTarget(cv::dnn::DNN_TARGET_OPENCL);

    return net;
}


cv::Mat Blobification(const cv::Mat img)
{
    cv::Mat blob_img;

    cv::dnn::blobFromImage(img, blob_img, 1, cv::Size(BLOB_SIZE, BLOB_SIZE),
                           cv::Scalar(), true, false);

    return blob_img;
}
