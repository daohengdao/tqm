#ifndef HQIMEN_H
#define HQIMEN_H

#include <string>
#include "deal.h"
#include "calendar.h"

// 临时
#include <iostream>

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

    Calendar* m_calendar = nullptr;                   // 日历

    std::map<std::string, int> juAndJieQi;            // 奇门局序数与节气的关系表
    std::map<std::string, std::string> oneYearData;   // 阴阳遁起局表
    std::map<int, std::string> cnNameDay;             // 农历中文名字日
    std::map<int, std::string> cnNameMonth;           // 农历中文名字月
    std::map<int, std::string> numName;               // 数字中文

private:

    void confirmNumth();          // 定哪一局
    void generate();              // 生成阴遁阳遁表

};

#endif // HQIMEN_H
