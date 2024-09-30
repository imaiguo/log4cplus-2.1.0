
# log4cplus 使用笔记


## Window上使用MSVC编译

设置编译环境
```bash
>
> cmd
> "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
> set Path=D:\devtools\log4cplus-2.1.0\bin;%Path%
> code -n
> cl.exe /ID:\\devtools\\log4cplus-2.1.0\\include /std:c++17 /Zc:__cplusplus UseProperties.cpp
```

### cmake 指定ninja编译
```bash
> mkdir build & cd build
> cmake .. -G Ninja  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=D:\devtools\log4cplus-2.1.0
> cmake .. -G Ninja  -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=D:\devtools\log4cplus-2.1.0
> ninja
> ninja install
```

### cmake指定sln编译
```bash
> cmd & vcvars64 & code
> mkdir build & cd build
> cmake ..
> devenv log4cplus.sln /Build
> devenv log4cplus.sln /Build "Debug|x64"
> devenv log4cplus.sln /Build "Release|x64"
```

### vscode运行调试helloworld

```bash
> cmd

> code
```


## Window上使用mingw64编译
### cmake 指定ninja编译
```bash
> cmd & mingw64 & code -n
> mkdir build & cd build
> cmake .. -G Ninja  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=D:\devtools\log4cplus.mingw64.2.1.0
> ninja
> ninja install
```

## Debian上编译


## git清理ignore文件

```bash
> git clean -xdf
>
```
