

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
add_definitions(-D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING)

set(AppName "UseProperties")

project (${AppName} LANGUAGES CXX)

if(MINGW)
    set(log4cplus_DIR D:/devtools/log4cplus.mingw64.2.1.0/lib/cmake/log4cplus)
else()
    set(log4cplus_DIR D:/devtools/log4cplus-2.1.0/lib/cmake/log4cplus)
endif()

find_package(log4cplus REQUIRED)

if(log4cplus_FOUND)
    message ("log4cplus found")
else()
    message (FATAL_ERROR "log4cplus isnot found")
endif()

add_executable(${AppName} src/main.cpp src/Log4cplusInit.cpp)

INCLUDE_DIRECTORIES(${log4cplus_INCLUDE_DIRS})

if(MINGW)
TARGET_LINK_LIBRARIES(${AppName} log4cplus::log4cplusU stdc++fs)
else()
TARGET_LINK_LIBRARIES(${AppName} log4cplus::log4cplusU)
endif()

file( COPY config/log4cplus.properties DESTINATION ./config/)
