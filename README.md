
# log4cplus 使用笔记


## windows上编译

设置编译环境

### cmake 指定ninja编译
```bash
> cmd & vcvars64 & code
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
> set Path=D:\devtools\log4cplus-2.1.0\bin;%Path%
> code
```



## Debian上编译
