#include "network.hpp"



cv::dnn::Net LoadNetwork()
{
    cv::dnn::Net net = cv::dnn::readNetFromDarknet(CONFIG_FILE, WEIGHT_FILE);
    net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
    net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);

    return net;
}


cv::Mat Blobification(const cv::Mat img)
{
    cv::Mat blob_img;

    cv::dnn::blobFromImage(img, blob_img, 1, cv::Size(BLOB_SIZE, BLOB_SIZE),
                           cv::Scalar(), true, false);

    return blob_img;
}
