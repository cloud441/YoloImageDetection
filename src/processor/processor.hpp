#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>

#include "../network/network.hpp"
#include "../mediamanager/mediamanager.hpp"

#define THRESHOLD 0.0001
#define V_MARGIN 20
#define H_MARGIN 100
#define V_SCREENSIZE 1080
#define H_SCREENSIZE 1920


void CameraProcess();
void ImageProcess(const char *filename);
void VideoProcess(const char *filename);
