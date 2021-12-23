#ifndef HQIMEN_H
#define HQIMEN_H

#include <string>
#include "deal.h"
#include "calendar.h"
#include <iostream>
#include <vector>

// 癸亥时全盘伏吟？？？

class HQiMen
{
public:
    // 打印结果
    void Run();


    // 传入内容 s 的参数值， m 的参数值，isAdd 为是否加 8 小时
    HQiMen(std::string p1, std::string p2, bool isAddEight);
    ~HQiMen();


private:

    int m_year = 0;               // 公历年
    int m_month = 0;              // 公历月
    int m_day = 0;                // 公历日
    int m_hour = 0;               // 公历时
    int m_min = 0;                // 公历分
    int m_sec = 0;                // 公历秒

    int style = 0;                // 第几局

    bool isYinDun = false;                            // 是否是阴遁
    bool isStyleAuto = false;                         // 是否是自动推算第几局
    bool isAdd = false;                               // 部分环境差 8 H，为 true 时补正 8 H

    std::string m_yuan;                               // 上中下哪一元 (汉字两个)
    std::string m_jieqi;                              // 归哪个节气管
    std::string zhiFu;                                // 直符是谁
    std::string zhiShi;                               // 直使是谁

    Calendar* m_calendar = nullptr;                   // 日历

    std::map<std::string, int> juAndJieQi;            // 奇门局序数与节气的关系表
    std::map<std::string, std::string> oneYearData;   // 阴阳遁起局表
    std::map<int, std::string> cnNameDay;             // 农历中文名字日
    std::map<int, std::string> cnNameMonth;           // 农历中文名字月
    std::map<int, std::string> numName;               // 数字中文
    std::map<std::string, std::string> liuJia;        // 六甲对应关系

    std::vector<std::string> jiuXing;                 // 九星的初始位置
    std::vector<std::string> jiuXingPaiLie;           // 九星的旋转位置
    std::vector<std::string> baMen;                   // 八门的初始位置
    std::vector<std::string> baMenPaiLie;             // 八门的旋转位置
    std::vector<std::string> baShenPaiLie;             // 八神的旋转位置

    std::vector<std::string> diPan;                   // 地盘信息
    std::vector<std::string> jiuXingRe;               // 九星的最终位置
    std::vector<std::string> baMenRe;                 // 八门的最终位置
    std::vector<std::string> baShenRe;                 // 八神的最终位置
    std::vector<std::string> tianPan;                 // 天盘信息


private:

    void confirmNumth();          // 定哪一局
    void generate();              // 生成阴遁阳遁表
    // 生成地盘，vector 长度为 9
    std::vector<std::string> generateDiPan();   
    // 找直符、直使
    void findZhifuZhishi();   
    // 转动直符、直使
    void turnZhifuZhishi();
    // 排八神
    void generateBaShen();
    // 排天盘
    void generateTianPan();

private:
    // 查看 data 在 m 中的下标
    int getIndex(std::vector<std::string> m, std::string data);     
};

#endif // HQIMEN_H
