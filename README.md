# 奇门遁甲排盘

时家奇门遁甲排盘命令行工具（**转盘-超接置润法**）。

# 开始

**直接执行给出使用说明**

![image](https://gitee.com/taynpg/tqm/raw/master/images/ea.png)

`-s` 和 `-m` 都给 0，可以查看当前时间的盘。

```shell
# 例如以下命令
./tqm -s 0 -m 0
```

运行结果：

![image](https://gitee.com/taynpg/tqm/raw/master/images/eb.png)

# 安装

安装有三种方法：

1. 如果是`Linux`，直接使用`make`命令即可。

2. 如果是`Windows`，分为两种情况。

   (1) 如果使用的是`Mingw64`，那么执行`mingw-build.bat`即可。

   (2) 如果使用的是`MSVC`编译器，那么需要打开本地的名为：`Developer Command Prompt for VS 2022`的终端（或其他版本），此终端默认配置了编译器需要的环境，在此命令行中执行`msvc-build.bat`即可，**注意直接执行是不行的**，要从上述地方中执行。

# 最后

如果你有好的建议或者发现了`BUG`，可以联系我：taynpg@163.com。