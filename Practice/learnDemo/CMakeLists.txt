project(learnDemo)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_VERBOSE_MAKEFILE on)

include_directories("/usr/include")
#link_directories("/usr/lib/x86_64-linux-gnu")

add_executable(sortVectorStruct sortVectorStruct.cpp spline.h)
target_link_libraries(sortVectorStruct gflags)


