project(LUADEMO)
cmake_minimum_required(VERSION 2.8)
# set(CMAKE_VERBOSE_MAKEFILE on)
SET(CMAKE_BUILD_TYPE "Debug")
include_directories(${CMAKE_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})
#设置可执行文件的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(TOP_DIR ${CMAKE_CURRENT_LIST_DIR})

include_directories("/usr/include")
link_directories("/usr/lib/x86_64-linux-gnu")
include_directories(${TOP_DIR}/deps/gflags/)
link_directories(${TOP_DIR}/deps/gflags)

add_executable(LuaDemo main.cpp)
# target_link_libraries(demo gflags pthread)
target_link_libraries(LuaDemo gflags lua5.3)


