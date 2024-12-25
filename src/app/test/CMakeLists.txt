add_executable(test-tf-1 test_tf_1.cpp)
target_link_libraries(test-tf-1 PRIVATE tensorflow-lite)

add_executable(test-cv-1 test_cv_1.cpp)
target_link_libraries(test-cv-1 PRIVATE OpenCV_LIB)
