
#pragma comment(lib, "D:/DevToolsMSVC/log4cplus.2.1.0/static/lib/log4cplusSU.lib")

// 静态链接log4plus库需要如下导入库
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "winspool.lib")
#pragma comment(lib, "comdlg32.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "oleaut32.lib")
#pragma comment(lib, "uuid.lib")
#pragma comment(lib, "odbc32.lib")
#pragma comment(lib, "odbccp32.lib")
#pragma comment(lib, "ws2_32.lib")

#include <iostream>

#include <log4cplus/helpers/loglog.h>
#include <log4cplus/logger.h>
#include <log4cplus/initializer.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/appender.h>
#include <log4cplus/loggingmacros.h>

using namespace std;
using namespace log4cplus::helpers;

void printMsgsMacros() {
    log4cplus::Logger logger = log4cplus::Logger::getRoot();

    LOG4CPLUS_DEBUG(logger, "This is a Debug statement...");
    LOG4CPLUS_WARN(logger, "This is a Warning...");

    cout << "Exiting printMsgs()..." << endl << endl;
}


int main() {
    // log4cplus::Initializer initializer;
    log4cplus::initialize();
    log4cplus::Logger logger = log4cplus::Logger::getRoot();

    log4cplus::SharedAppenderPtr append(new log4cplus::ConsoleAppender(false, true));
    append->setLayout(std::unique_ptr<log4cplus::Layout>(new log4cplus::PatternLayout(LOG4CPLUS_TEXT("[%p] %D{%Y-%m-%d %H:%M:%S.%q}:%t %F:%L \"%m\"%n"))));
    logger.addAppender(append);

    printMsgsMacros();
    return 0;
}
