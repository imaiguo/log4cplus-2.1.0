﻿

#include <iomanip>
#include <iostream>

#include <string>
#include <locale>
#include <codecvt>

#include <log4cplus/loggingmacros.h>
#include <log4cplus/logger.h>

#ifdef __MINGW64__
#include <experimental/filesystem>
#else
#include <filesystem>
#endif

#include "Log4cplusInit.h"

int main(int argc, char **argv){

    //  初始化配置
    Log4cplusInitFunc(argv[0]);
#ifdef __MINGW64__
    std::experimental::filesystem::create_directory("log");
else
    std::filesystem::create_directory("log");
#endif

    // 开始使用
    log4cplus::Logger logger = log4cplus::Logger::getRoot();

    // trace
    LOG4CPLUS_TRACE(logger, "test to log a message.");

    // debug
    LOG4CPLUS_DEBUG(logger, "test to log a message:["<< 2 << "]" );

    // info
    LOG4CPLUS_INFO(logger, "test to log a message:" << "[ 1 + 1 = " << 1 + 1 << "]");

    // warn
    int i = 10;
    LOG4CPLUS_WARN(logger, "test to log a message");

    // error
    LOG4CPLUS_ERROR(logger, "ooooooh, there is an error....");
    
    //fatal
    LOG4CPLUS_FATAL(logger, "oh, my god! the fatal error occur!!!!!!!!!");


    LOG4CPLUS_DEBUG(logger, "This is a bool: " << true);
    LOG4CPLUS_INFO(logger, "This is a char: " << 'x');
    LOG4CPLUS_WARN(logger, "This is a int: " << 1000);
    LOG4CPLUS_ERROR(logger, "This is a long(hex): " << std::hex << 100000000);
    LOG4CPLUS_FATAL(logger, "This is a double: " << std::setprecision(15) << 1.2345234234);

    // log4cplus.logger.test
    log4cplus::Logger loggerTest  = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("test"));
    LOG4CPLUS_TRACE(loggerTest,"anther logger,trace");
    LOG4CPLUS_ERROR(loggerTest,"anther logger,error ");
    log4cplus::Logger::shutdown();
    return 0;
}
