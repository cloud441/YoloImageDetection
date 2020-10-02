#include "processor.hpp"

#define THRESHOLD 0.0001
#define V_MARGIN 20
#define H_MARGIN 100



static void PrintOnImage(cv::Mat img, cv::Mat out_mat,
                        int index, double confidence,
                        cv::Point max_pos)
{
    int width = (int)(out_mat.at<float>(index, 2) * img.cols + V_MARGIN);
    int height = (int)(out_mat.at<float>(index, 3) * img.rows + H_MARGIN);
    int left = (int)(out_mat.at<float>(index, 0) * img.cols) - width / 2;
    int top = (int)(out_mat.at<float>(index, 1) * img.rows) - height / 2;

    std::stringstream stream;
    stream << max_pos.x;
    cv::putText(img, stream.str(), cv::Point(left, top), 1, 2,
                cv::Scalar(max_pos.x * 10, 255, 255), 2, false);

    cv::rectangle(img, cv::Rect(left, top, width, height),
                cv::Scalar(max_pos.x * 10, 0, 0), 2, 8, 0);
}




static void AddDetectedObjects(cv::Mat img, cv::Mat out_mat)
{
    int detections_nb = out_mat.rows;
    int class_score_pos = out_mat.cols;

    for (int i = 0; i < detections_nb; i++)
    {
        cv::Mat scores = out_mat.row(i).colRange(5, class_score_pos);
        cv::Point max_pos;
        double confidence;

        cv::minMaxLoc(scores, 0, &confidence, 0, &max_pos);

        if (confidence > THRESHOLD)
            PrintOnImage(img, out_mat, i, confidence, max_pos);
    }
}



static void ImageFlowProcess(const bool is_camera, const char *filename = "")
{
    cv::VideoCapture capture;

    if (is_camera)
        capture.open(0);
    else
        capture.open(filename);

    if (!capture.isOpened())
    {
        std::cerr << "Error in Video loading." << std::endl;
        return;
    }

    std::string title = is_camera ?  "YoloCam InRealTime" : "YoloCam Video Recognition";
    cv::namedWindow(title.c_str(), cv::WINDOW_NORMAL);
    cv::resizeWindow(title.c_str(), 1920, 1080);

    cv::Mat frame;
    
    while (true)
    {
        capture >> frame;

        cv::dnn::Net net = LoadNetwork();
        net.setInput(Blobification(frame), "", 1.0 / 255.0, 0);

        cv::Mat out_mat;
        net.forward(out_mat);

        AddDetectedObjects(frame, out_mat);

        cv::imshow(title.c_str(), frame);

        if(cv::waitKey(33) != -1)
            break;
    }

    cv::destroyWindow(title);
}



void CameraProcess()
{
    ImageFlowProcess(true);
}




void ImageProcess(const char *filename)
{
    cv::Mat img;
    img = cv::imread(filename, cv::IMREAD_COLOR );

    if (img.empty())
    {
        std::cerr << "Image couldn't be load." << std::endl;
        return;
    }

    cv::dnn::Net net = LoadNetwork();
    net.setInput(Blobification(img), "", 1.0 / 255.0, 0);

    cv::Mat out_mat;
    net.forward(out_mat);

    AddDetectedObjects(img, out_mat);

    ShowImage(img);
}




void VideoProcess(const char *filename)
{
    ImageFlowProcess(false, filename);
}
