#include "yolocam.hpp"


int PrintHelp()
{
    std::cerr << "Usage: ./yoloCam.exe <Mode> [Dataname]" << std::endl;
    return -1;
}


int main(int argc, char** argv)
{
    if (argc < 2)
        return PrintHelp();


    if (std::string(argv[1]) == "camera" && argc == 2)
    {
        CameraProcess();
    }

    else if (std::string(argv[1]) == "image" && argc == 3)
    {
        ImageProcess(argv[2]);
    }

    else if (std::string(argv[1]) == "video" && argc == 3)
    {
        VideoProcess(argv[2]);
    }

    else
        return PrintHelp();
}
