#include <iostream>
#include <tensorflow/lite/version.h>

int main() {
    std::cout << "TensorFlow Lite version: " << TFLITE_VERSION_STRING << std::endl;
    return 0;
}
