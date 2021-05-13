#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <thread>
#include <chrono>
#include <unistd.h>
#include "Eigen/Eigen"
#include "deps/liblog/log_manager.h"
// #include "logmanager.hpp"

void init()
{
    LogInst->init(); 
}

int main()
{
    init();
    LOG_INFO( "Hello, I am TestEigen Client." );
    
    // sleep(1);
    //休眠多少毫秒
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    return 0;
}
