# 奇门遁甲排盘

奇门遁甲排盘命令行工具（暂只支持**时家奇门的转盘法，置润局**）。

# 开始

**直接执行给出使用说明**

```shell
***************************************************************************
【第一个参数介绍：门派确定(x表示功能暂未实现，v表示已实现)】
     (x)tqm -n  表示年家奇门。
     (x)tqm -y  表示月家奇门。
     (x)tqm -r  表示日家奇门。
     (v)tqm -s  表示时家奇门[置润][转盘法]。

【第二个参数介绍：确定详情（以下以时家奇门[置润][转盘法]为例）】

      时家必须传入两个参数，-s 指定日期，-m 指定手动选局。

      <传入参数示例>tqm -s 0 -m 0
      [s = 0]表示用当前的时间起局，[m = 0]表示自动计算第几局。
      (-s -m 必须要有且顺序不能颠倒)

      若 s 后的参数不为 0，参数格式(公历24小时制)(个位数需补0):
      YYYY-MM-DD-HH-MM-SS 或者 YYYY-MM-DD-HH。

      若 m 后的参数不为0，参数示例格式: yi8(阴遁8局), ya7(阳遁7局)。

      说明1: 月、日、时、如果是个位数，前面需要补 0， 如8月输入08。
      说明2: 如果自动获取的时间慢了8小时，最后面添加 -a 参数补正。
      说明3：时间跨度(1901-01-01-00-00-00 到 2098-12-31-23-59-59)
***************************************************************************
```

`-s` 和 `-m` 都给 0，可以查看当前时间的农历信息，或者 `-s` 给出具体日期查看对应日期日历。

```shell
# 例如以下命令
./tqm -s 0 -m 0
```

运行结果：

```shell
===========================================
[公元2021年12月23日13时0分46秒]
[大雪下元][阴遁1局][v0.1.4]
农历:二零二一年 冬月二十 未时
干支:辛 庚 乙 癸
     丑 子 巳 未
===========================================
| 六合        | 太阴        | 腾蛇        |
| 天心    己  | 天蓬   [丁] | 天任    乙  |
| 景门    辛  | 死门    丙  | 惊门    癸  |
===========================================
| 白虎   (空) |             | 值符        |
| 天柱    戊  |      庚     | 天冲    壬  |
| 杜门    壬  |             | 开门    戊  |
===========================================
| 玄武   (马) | 九地        | 九天        |
| 天芮    癸庚| 天英    丙  | 天辅   [辛] |
| 伤门    乙  | 生门    丁  | 休门    己  |
===========================================
说明：上盘仅为排版测试，内容并不正确。
节气:12月07日 [大雪] 05:56:55
节气:12月21日 [冬至] 23:59:09
===========================================
```

# 当前进度

因为是零散时间开发，因此，开发到哪里就记到哪里。

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