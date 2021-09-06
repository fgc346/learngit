project(pythonTest)
cmake_minimum_required(VERSION 3.12)
SET(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_VERBOSE_MAKEFILE on)

# find_package(Python3 COMPONENTS Development)

include_directories(/home/erma/anaconda3/envs/py36/include/python3.6m)

# include_directories(${Python3_INCLUDE_DIRS})
link_directories(/home/erma/anaconda3/envs/py36/lib/)

add_executable(mypy main.cpp)
target_link_libraries(mypy python3.6m)


