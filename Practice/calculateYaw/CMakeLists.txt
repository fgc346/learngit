project(calculateYaw)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_VERBOSE_MAKEFILE on)

include_directories("/usr/include")
#link_directories("/usr/lib/x86_64-linux-gnu")

add_executable(calculateYaw calculateYaw.cpp)
target_link_libraries(calculateYaw gflags)


