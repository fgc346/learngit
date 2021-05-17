project(LUADEMO)
cmake_minimum_required(VERSION 2.8)
# set(CMAKE_VERBOSE_MAKEFILE on)
SET(CMAKE_BUILD_TYPE "Debug")
include_directories(${CMAKE_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})
#设置可执行文件的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
#设置生成的动态库的输出目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/)

set(TOP_DIR ${CMAKE_CURRENT_LIST_DIR})

#lua安装在本机的include和动态库地址
# include_directories("/usr/include")
# link_directories("/usr/lib/x86_64-linux-gnu")
include_directories(${TOP_DIR}/deps/gflags/)
link_directories(${TOP_DIR}/deps/gflags)
#将lua作为第三方库提取出来放置在/deps/lua目录下
include_directories(${TOP_DIR}/deps/lua5.1/include)
link_directories(${TOP_DIR}/deps/lua5.1/lib)


add_library(firstFile SHARED firstFile.cpp)
target_link_libraries(firstFile lua5.1)

add_executable(LuaDemo main.cpp sample.cpp)
# target_link_libraries(demo gflags pthread)
target_link_libraries(LuaDemo gflags lua5.1)


