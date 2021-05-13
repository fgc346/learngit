cmake_minimum_required(VERSION 2.8.3)
PROJECT (TESTEIGEN)
SET(CMAKE_BUILD_TYPE "Debug")
include_directories(${CMAKE_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})
#设置可执行文件的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(TOP_DIR ${CMAKE_CURRENT_LIST_DIR})

SET(SRC_LIST ${TOP_DIR}/main.cpp 
             ${TOP_DIR}/deps/liblog/log_manager.cpp 
             ${TOP_DIR}/deps/liblog/log_manager.h
            #  ${TOP_DIR}/log_manager.cpp 
            #  ${TOP_DIR}/logmanager.hpp  
             )
#include_directories(${TOP_DIR}/deps/liblog/)
include_directories(${TOP_DIR}/deps/Eigen-3.3/)

link_directories(${TOP_DIR}/deps/liblog)


add_executable(EigenDemo ${SRC_LIST})
# target_include_directories(libdriveDemo PUBLIC
#         ${TOP_DIR}/deps/libdrive/include/)
target_link_libraries(EigenDemo 
                                            vtslog pthread)
