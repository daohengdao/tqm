# 奇门遁甲排盘

奇门遁甲排盘命令行工具（暂只支持**时家奇门的转盘法，置润局**）。

# 开始

**直接执行给出使用说明**

![](https://github.com/taynpg/tqm/raw/main/images/start.png)


`-s` 和 `-m` 都给 0，可以查看当前时间的农历信息，或者 `-s` 给出具体日期查看对应日期日历。

```shell
# 例如以下命令
./tqm -s 0 -m 0
```

运行结果：

![](https://github.com/taynpg/tqm/raw/main/images/two.png)

```shell
# 例如以下命令
./tqm -s 1991-05-27-15 -m 0
```

运行结果：

![](https://github.com/taynpg/tqm/raw/main/images/three.png)

# 当前进度

因为是零散时间开发，因此，开发到哪里就记到哪里。

**已实现功能：**

1. 奇门阴遁几局阳遁几局判断

# 安装

环境要求：g++、make。

```shell
# 1.拉取代码
git clone https://github.com/taynpg/tqm
# 2.进入到项目目录中
cd tqm
# 3-1.如果是windows系统执行 build.bat
终端中./build.bat 或 鼠标双击打开 build.bat
# 3-2.如果是linux系统有如下两种方法执行脚本。
(1) 直接 sh build.sh 即可
(2) 如果没有 sh 命令，先 chmod +x ./build.sh 给于 build.sh 可以执行权限。
然后 ./build.sh 即可。
```

构建生成的二进制文件在项目根目录下，名为**tqm**，如果有其他配置选项，可以手动构建。