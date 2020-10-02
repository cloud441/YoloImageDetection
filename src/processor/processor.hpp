#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>

#include "../network/network.hpp"
#include "../mediamanager/mediamanager.hpp"

void CameraProcess();
void ImageProcess(const char *filename);
void VideoProcess(const char *filename);
