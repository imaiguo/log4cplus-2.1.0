﻿
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/helpers/fileinfo.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/initializer.h>
#include <thread>

#include <iostream>

#include <string>
#include <locale>
#include <codecvt>

using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;

Logger log_1;
Logger log_2;
Logger log_3;

void printMsgs(Logger& logger) {
    LOG4CPLUS_TRACE_METHOD(logger, LOG4CPLUS_TEXT("printMsgs()"));
    LOG4CPLUS_DEBUG(logger, "printMsgs()");
    LOG4CPLUS_INFO(logger, "printMsgs()");
    LOG4CPLUS_WARN(logger, "printMsgs()");
    LOG4CPLUS_ERROR(logger, "printMsgs()");
}

//convert string to wstring
inline std::wstring to_wide_string(const std::string& input)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return converter.from_bytes(input);
}

string getBinPath(string strPath) {
    size_t pos = strPath.find_last_of("\\");
    string newpath = strPath.substr(0, pos+1);
    return newpath;
}

log4cplus::tstring getPropertiesFileArgument (int argc, char * argv[]) {
    string path = getBinPath(argv[0]);
    if (argc >= 2) {
        char const * arg = argv[1];
        log4cplus::tstring file = LOG4CPLUS_C_STR_TO_TSTRING (arg);
        log4cplus::helpers::FileInfo fi;
        if (getFileInfo (&fi, file) == 0)
            return file;
    }
    log4cplus::tstring tPath = to_wide_string( path + "log4cplus.properties" );
    wcout << "current config -> " << tPath <<endl;
    return tPath;
}

int main(int argc, char * argv[]) {
    log4cplus::Initializer initializer;
    log_1 =  Logger::getInstance(LOG4CPLUS_TEXT("test.log_1"));
    log_2 =  Logger::getInstance(LOG4CPLUS_TEXT("test.log_2"));
    log_3 =  Logger::getInstance(LOG4CPLUS_TEXT("test.log_3"));

    // LogLog::getLogLog()->setInternalDebugging(true);
    Logger root = Logger::getRoot();
    try {
        ConfigureAndWatchThread configureThread(getPropertiesFileArgument(argc, argv), 1 * 1000);

        LOG4CPLUS_WARN(root, "Testing....");

        for(int i=0; i<4; ++i) {
            printMsgs(log_1);
            printMsgs(log_2);
            printMsgs(log_3);
            // std::this_thread::sleep_for (std::chrono::seconds (1));
        }
    }
    catch(...) {
        // tcout << LOG4CPLUS_TEXT("Exception...") << endl;
        LOG4CPLUS_FATAL(root, "Exception occurred...");
    }

    // tcout << LOG4CPLUS_TEXT("Exiting main()...") << endl;
    return 0;
}
