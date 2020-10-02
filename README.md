# YoloImageDetection
Implementation of Form detection basedon  Image processing with OpenCV and Yolo project.





# BUILD THE PROJECT:

run the following commands from the root of the repository:
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make




# RUN THE PROJECT:

the executable binary yoloCam.exe is used according to the following:
    --> ./yoloCam.exe <mode> [filepath]

all modes:
    image <imagepatn>  |--> Detect forms from an image.
    video <videopath>  |--> Detect forms from a video.
    camera             |--> Detect forms from the hardware camera in real time.


# MISCELLANEOUS:

--> DATA DIRECTORY:
    The data directory contains some image/video to test the project AND the weight/configuration file
    used by yolo project. These are the pre-trained neural network of form detection and the according
    configuration file.
