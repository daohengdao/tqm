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

`-s` 和 `-m` 都给 0，可以查看当前时间的盘。

```shell
# 例如以下命令
./tqm -s 0 -m 0
```

运行结果（README文档界面有错位，但在终端中排版是完全整齐，严丝合缝，没有一点错位的）：

```shell
===========================================
[公元2021年12月23日22时45分48秒][版本V0.3.3]
===========================================
农历:二零二一年 冬月二十 亥时
干支:辛 庚 乙 丁
     丑 子 巳 亥     (天禽星与天芮星同位置)
===========================================
值符:天任  值使: 生门   [大雪下元][阴遁1局]
===========================================
| 值符   (马) | 九天   (空) | 九地   (空) |
|*天任    庚  | 天冲    丙  | 天辅   [丁] |
| 开门    丁  | 休门    己  |*生门    乙  |
===========================================
| 腾蛇        |             | 玄武        |
| 天蓬    戊  |      癸     | 天英    己  |
| 惊门    丙  |             | 伤门    辛  |
===========================================
| 太阴        | 六合        | 白虎        |
| 天心    壬  | 天柱    辛  | 天芮    乙癸|
| 死门    庚  | 景门    戊  | 杜门    壬  |
===========================================
节气:12月07日 [大雪] 05:56:55
节气:12月21日 [冬至] 23:59:09
===========================================
```

以下是截图：

![image](https://github.com/taynpg/tqm/blob/main/images/example.png)

# 当前进度

因为是零散时间开发，因此，开发到哪里就记到哪里。

1. 奇门阴遁几局阳遁几局判断
2. 已完成排盘(已支持自定义指定几局)

# 安装

环境要求：g++、make，也可以使用 msvc 编译器。

```shell

# 1.拉取代码
git clone https://github.com/taynpg/tqm

# 2.进入到项目目录中
cd tqm

3-1.如果是windows系统执行 build.bat （使用的是Mingw64） 或者 自行使用 msvc 手动编译

3-2.如果是linux系统使用 make 命令即可
```

# GUI桌面版本

下面是我开发的桌面版本，暂只完成了排盘排版，支持记录，查询等功能。

![image](https://github.com/taynpg/tqm/blob/main/images/example1.png)