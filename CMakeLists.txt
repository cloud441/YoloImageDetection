cmake_minimum_required(VERSION 2.8)
project( yoloCam )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( yoloCam.exe 
                src/yolocam.cpp
                src/processor/processor.cpp
                src/network/network.cpp
                src/mediamanager/mediamanager.cpp)
target_link_libraries( yoloCam.exe ${OpenCV_LIBS} )
