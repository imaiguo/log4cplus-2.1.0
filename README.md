
# log4cplus 使用笔记


## 1. Window上使用MSVC编译

- cmake 指定ninja编译
```bash
>
> mkdir build & cd build
> cmake .. -G Ninja  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=D:\DevToolsMSVC\log4cplus.2.1.0
> cmake .. -G Ninja  -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=D:\DevToolsMSVC\log4cplus.2.1.0
> ninja
> ninja -v # 打印详细编译过程
> ninja install
>
```

- cmake指定sln编译
```bash
> cmd & vcvars64 & code
> mkdir build & cd build
> cmake ..
> devenv log4cplus.sln /Build
> devenv log4cplus.sln /Build "Debug|x64"
> devenv log4cplus.sln /Build "Release|x64"
```

- 设置log4cplus开发环境
```bash
>
> cmd
> vcvars64.bat
> set Path=D:\DevToolsMSVC\log4cplus.2.1.0\bin;%Path%
> code -n
> cl.exe /ID:\\DevToolsMSVC\\log4cplus.2.1.0\\include /std:c++17 /Zc:__cplusplus UseProperties.cpp
```


## 2. 使用mingw64编译
### cmake 指定ninja编译
```bash
> cmd & mingw64 & code -n
> mkdir build & cd build
> cmake .. -G Ninja  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=D:\DevToolsMingW\log4cplus.mingw64.2.1.0
> ninja
> ninja install
```

## Debian上编译
### cmake 指定ninja编译
```bash
> mkdir build & cd build
> cmake .. -G Ninja  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/opt/devtools/log4cplus-2.1.0
> cmake .. -G Ninja  -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=/opt/devtools/log4cplus-2.1.0
> ninja
> ninja install
```

## git清理ignore文件

```bash
> git clean -xdf
>
```
