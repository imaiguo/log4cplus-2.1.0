# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

set(AppName "loglog")

project (${AppName} LANGUAGES CXX)
set(CMAKE_BUILD_TYPE "Debug")

# set(log4cplus_DIR D:/devtools/log4cplus-2.1.0/lib/cmake/log4cplus)
# find_package(log4cplus REQUIRED)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    find_package(log4cplus PATHS "/opt/devtools/log4cplus-2.1.0/lib/cmake" REQUIRED)
else()
    find_package(log4cplus PATHS "D:/devtools/log4cplus-2.1.0/lib/cmake/log4cplus" REQUIRED)
endif()


if(log4cplus_FOUND)
    message ("log4cplus found")
else()
    message (FATAL_ERROR "log4cplus isnot found")
endif()

add_executable(${AppName} main.cpp)

# INCLUDE_DIRECTORIES(D:/devtools/log4cplus-2.1.0/include)
# INCLUDE_DIRECTORIES(third_party_include ${log4cplus_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${log4cplus_INCLUDE_DIRS})

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    TARGET_LINK_LIBRARIES(${AppName} log4cplus::log4cplus)
else()
    TARGET_LINK_LIBRARIES(${AppName} log4cplus::log4cplusU)
endif()


# vscode里调试 设置环境
# set Path=D:\devtools\log4cplus-2.1.0\bin;%Path%