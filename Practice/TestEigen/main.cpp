#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <thread>
#include <chrono>
#include <unistd.h>
#include "Eigen/Eigen"
// #include "logmanager.hpp"


int main()
{
    printf("hello,world!\n");
    // sleep(1);
    //休眠多少毫秒
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    return 0;
}
