
#include <cstdlib>
#include <cstdio>
#include "log4cplus/initializer.h"
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/loggingmacros.h>
#include <iomanip>
#include <iostream>

#include <string>
#include <locale>
#include <codecvt>
#include <filesystem>
 
using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;

int random(){
    return 2;
}

//convert string to wstring
inline std::wstring to_wide_string(const std::string& input)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return converter.from_bytes(input);
}

log4cplus::tstring getBinPath(string strPath) {
    size_t pos = strPath.find_last_of("\\");
    string newpath = strPath.substr(0, pos+1);
    log4cplus::tstring tPath = to_wide_string( newpath + "log4cplus.properties" );
    wcout << "current config -> " << tPath <<endl;
    return tPath;
}

int main(int argc, char **argv)
{
    // 初始化配置
    log4cplus::Initializer initializer;
    // log4cplus::initialize(); // 阻塞模式

    std::filesystem::create_directory("log");
    PropertyConfigurator::doConfigure(getBinPath(argv[0]));

    // 开始使用
    Logger logger = Logger::getRoot();

    // trace
    LOG4CPLUS_TRACE(logger, "trace and get the fingerprint: " << "random integer: " << random());

    // debug
    LOG4CPLUS_DEBUG(logger, "this is debug log: " << "random integer: "<< random());

    // info
    LOG4CPLUS_INFO(logger, "the information centry...." << "[ 1 + 1 = " << 1 + 1 << "]");

    // warn
    int i = 10;
    LOG4CPLUS_WARN(logger, "Writing warning messages to log...." << i);

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
    Logger loggerTest  = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("test"));
    LOG4CPLUS_TRACE(loggerTest,"anther logger,trace");
    LOG4CPLUS_ERROR(loggerTest,"anther logger,error ");
    log4cplus::Logger::shutdown();
    return 0;
}

