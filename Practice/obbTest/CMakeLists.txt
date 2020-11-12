project(obbTest)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_VERBOSE_MAKEFILE on)

include_directories("/usr/include")
link_directories("/usr/lib/x86_64-linux-gnu")

add_executable(obbDemo 2dobbDemo.cpp 2dobb.h)
target_link_libraries(obbDemo -lGL -lGLU -lglut)


