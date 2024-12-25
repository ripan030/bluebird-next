cmake_minimum_required(VERSION 3.28)
project(bluebird-next)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        tensorflow
        GIT_REPOSITORY https://github.com/tensorflow/tensorflow.git
        GIT_PROGRESS TRUE
        GIT_SHALLOW TRUE
        GIT_TAG v2.17.0
        GIT_SUBMODULES_RECURSE TRUE
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
        SOURCE_SUBDIR tensorflow/lite
)

FetchContent_MakeAvailable(tensorflow)

include(ExternalProject)

ExternalProject_Add(
    OpenCV
    PREFIX ${CMAKE_BINARY_DIR}/ep-opencv
    GIT_REPOSITORY https://github.com/opencv/opencv.git
    GIT_TAG 4.10.0
    GIT_SHALLOW TRUE
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/opencv_install
        -DBUILD_SHARED_LIBS=ON
        -DBUILD_TESTS=OFF
        -DCMAKE_BUILD_TYPE=Release
        -DCMAKE_CXX_STANDARD=14
        -DCMAKE_CXX_STANDARD_REQUIRED=ON
        -DBUILD_JAVA=OFF
        -DBUILD_OPENCV_JS=OFF
        -DBUILD_opencv_highgui=ON
        -DWITH_GTK=ON
    BUILD_ALWAYS OFF
)

add_library(OpenCV_LIB INTERFACE)
add_dependencies(OpenCV_LIB OpenCV)

target_include_directories(OpenCV_LIB INTERFACE ${CMAKE_BINARY_DIR}/opencv_install/include/opencv4)

file(GLOB OPENCV_LIBS "${CMAKE_BINARY_DIR}/opencv_install/lib/libopencv_*.so")

target_link_libraries(OpenCV_LIB INTERFACE ${OPENCV_LIBS})

add_subdirectory(src)
