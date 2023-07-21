# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

set(AppName "configandwatch")

project (${AppName} LANGUAGES CXX)
set(CMAKE_BUILD_TYPE "Debug")

# set(log4cplus_DIR D:/devtools/log4cplus-2.1.0/lib/cmake/log4cplus)
# find_package(log4cplus REQUIRED)

find_package(log4cplus PATHS "D:/devtools/log4cplus-2.1.0/lib/cmake/log4cplus" REQUIRED)

if(log4cplus_FOUND)
    message ("log4cplus found")
else()
    message (FATAL_ERROR "log4cplus isnot found")
endif()

add_executable(${AppName} src/main.cpp)

# INCLUDE_DIRECTORIES(D:/devtools/log4cplus-2.1.0/include)
# INCLUDE_DIRECTORIES(third_party_include ${log4cplus_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${log4cplus_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${AppName} log4cplus::log4cplusU)


file( COPY config/log4cplus.properties DESTINATION ./)

# vscode里调试 设置环境
# set Path=D:\devtools\log4cplus-2.1.0\bin;%Path%