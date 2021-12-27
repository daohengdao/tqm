#include "hqimen.h"
#include "public.h"

HQiMen::HQiMen(std::string p1, std::string p2, bool isAddEight)
{
    m_calendar = new Calendar;

    this->isAdd = isAddEight;

    if (p1 == "0")
    {
        std::string date = m_calendar->GetSysDateTimeMill();
        if (isAdd)
        {
            int se = 3600 * 8;
            date = m_calendar->GetDateFromTimeDiffAndBase(date, se);
        }

        this->m_year = std::stoi(date.substr(0, 4));
        this->m_month = std::stoi(date.substr(4, 2));
        this->m_day = std::stoi(date.substr(6, 2));
        this->m_hour = std::stoi(date.substr(8, 2));
        this->m_min = std::stoi(date.substr(10, 2));
        this->m_sec = std::stoi(date.substr(12, 2));
    }
    else
    {
        std::string su = ReplaceString(p1, "-", "");
        this->m_year = std::stoi(su.substr(0, 4));
        this->m_month = std::stoi(su.substr(4, 2));
        this->m_day = std::stoi(su.substr(6, 2));
        this->m_hour = std::stoi(su.substr(8, 2));
        this->m_min = std::stoi(su.substr(10, 2));
        this->m_sec = std::stoi(su.substr(12, 2));
    }

    if (p2 == "0")
    {
        this->isStyleAuto = true;
    }
    else
    {
        if (p1.substr(0, 2) == "yi")
        {
            this->isYinDun = true;
        }
        this->style = std::stoi(p2.substr(2, 1));
    }

    // 奇门局序数与节气的关系表
    juAndJieQi =
    {
        {"冬至", 1741}, {"惊蛰", 1741}, {"小寒", 2851}, {"大寒", 3961}, {"春分", 3961}, {"雨水", 9631},
        {"清明", 4171}, {"立夏", 4171}, {"立春", 8521}, {"谷雨", 5281}, {"小满", 5281}, {"芒种", 6391},
        {"夏至", 9360}, {"白露", 9360}, {"小暑", 8250}, {"寒露", 6930}, {"立冬", 6930}, {"处暑", 1470},
        {"霜降", 5820}, {"小雪", 5820}, {"大雪", 4710}, {"大暑", 7140}, {"秋分", 7140}, {"立秋", 2580}
    };
    cnNameDay =
    {
        {1, "初一"}, {2, "初二"}, {3, "初三"}, {4, "初四"}, {5, "初五"}, {6, "初六"}, {7, "初七"},
        {8, "初八"}, {9, "初九"}, {10, "初十"}, {11, "十一"}, {12, "十二"}, {13, "十三"}, {14, "十四"},
        {15, "十五"}, {16, "十六"}, {17, "十七"}, {18, "十八"}, {19, "十九"}, {20, "二十"}, {21, "二十一"},
        {22, "二十二"}, {23, "二十三"}, {24, "二十四"}, {25, "二十五"}, {26, "二十六"}, {27, "二十七"},
        {28, "二十八"}, {29, "二十九"}, {30, "三十"}
    };
    cnNameMonth =
    {
        {1, "正月"}, {2, "二月"}, {3, "三月"}, {4, "四月"}, {5, "五月"}, {6, "六月"},
        {7, "七月"}, {8, "八月"}, {9, "九月"}, {10, "十月"}, {11, "冬月"}, {12, "腊月"},
    };
    numName =
    {
        {1, "一"}, {2, "二"}, {3, "三"}, {4, "四"}, {5, "五"},
        {6, "六"}, {7, "七"}, {8, "八"}, {9, "九"}, {10, "十"}, {0, "零"}
    };
    // 九星的初始位置
    jiuXing =
    {
        "天蓬", "天芮", "天冲", "天辅", "天禽", "天心", "天柱", "天任", "天英"
    };
    // 八门的初始位置           
    baMen = 
    {
        "休门", "死门", "伤门", "杜门", "死门", "开门", "惊门", "生门", "景门"
    };               
    // 六甲对应关系  
    liuJia = 
    {
        {"甲子", "戊"}, {"甲戌", "己"}, {"甲申", "庚"}, 
        {"甲午", "辛"}, {"甲辰", "壬"}, {"甲寅", "癸"}
    };  
    // 九星的旋转位置
    jiuXingPaiLie = 
    {
        "天蓬", "天任", "天冲", "天辅", "天英", "天芮", "天柱", "天心"
    };
    // 八门旋转位置
    baMenPaiLie = 
    {
        "休门", "生门", "伤门", "杜门", "景门", "死门", "惊门", "开门"
    };
    // 八神的旋转位置
    baShenPaiLie = 
    {
        "值符", "腾蛇", "太阴", "六合", "白虎", "玄武", "九地", "九天"
    };
    // 十二长生和宫的对应
    zhangSheng = 
    {
        {"子", 0}, {"丑", 7}, {"寅", 7}, {"卯", 2}, {"辰", 3}, {"巳", 3},
        {"午", 8}, {"未", 1}, {"申", 1}, {"酉", 6}, {"戌", 5}, {"亥", 5}
    };
    // 十二地支三合的首个
    sanHe = 
    {
        {"子", "申"}, {"丑", "巳"}, {"寅", "寅"}, {"卯", "亥"}, {"辰", "申"}, {"巳", "巳"},
        {"午", "寅"}, {"未", "亥"}, {"申", "申"}, {"酉", "巳"}, {"戌", "寅"}, {"亥", "亥"}
    };
    // 地支相冲
    xiangChong = 
    {
        {"申", "寅"}, {"巳", "亥"}, {"寅", "申"}, {"亥", "巳"}
    };
}
HQiMen::~HQiMen()
{
    delete m_calendar;
    m_calendar = nullptr;
}
// 打印结果
void HQiMen::Run()
{
    auto the_date = m_calendar->GetStandardDateTime(m_year, m_month, m_day, m_hour, m_min, m_sec);
    if (m_calendar->GetDateTimeDiffTwo(the_date, "19010101000000") < 0 ||
        m_calendar->GetDateTimeDiffTwo("20981231235959", the_date) < 0)
    {
        std::cout << "你好，本程序仅支持1901年01月01日0时0分0秒以后，" << std::endl;
        std::cout << "               2098年12月31日23时59分59秒以前。" << std::endl;
        return;
    }
    std::cout << "===========================================" << std::endl;
    std::cout << "[公元" << m_year << "年" << m_month << "月" << m_day
        << "日" << m_hour << "时" << m_min << "分" << m_sec << "秒]";
    std::cout << "[" << version << "]" << std::endl;

    bool re = m_calendar->SetSolarDate(m_year, m_month, m_day, m_hour, m_min, m_sec);
    confirmNumth();
    if (re)
    {
        std::string NianGan = m_calendar->zhSubstr(m_calendar->lunarYearZhu, 2, 0, 1);
        std::string NianZhi = m_calendar->zhSubstr(m_calendar->lunarYearZhu, 2, 1, 1);
        std::string YueGan = m_calendar->zhSubstr(m_calendar->lunarMonthZhu, 2, 0, 1);
        std::string YueZhi = m_calendar->zhSubstr(m_calendar->lunarMonthZhu, 2, 1, 1);
        std::string RiGan = m_calendar->zhSubstr(m_calendar->lunarDayZhu, 2, 0, 1);
        std::string RiZhi = m_calendar->zhSubstr(m_calendar->lunarDayZhu, 2, 1, 1);
        std::string ShiGan = m_calendar->zhSubstr(m_calendar->lunarHourZhu, 2, 0, 1);
        std::string ShiZhi = m_calendar->zhSubstr(m_calendar->lunarHourZhu, 2, 1, 1);

        int lunarY = m_calendar->lunarYear;
        std::cout << "===========================================" << std::endl;
        std::cout << "农历:"
        << numName[lunarY / 1000]
        << numName[(lunarY - (lunarY / 1000) * 1000) / 100]
        << numName[((lunarY - (lunarY % 10)) / 10) % 10]
        << numName[lunarY % 10] << "年 "
        << cnNameMonth[m_calendar->lunarMonth]
        << cnNameDay[m_calendar->lunarDay]
        << " "
        << m_calendar->zhSubstr(m_calendar->lunarHourZhu, 2, 1, 2)
        << "时" << std::endl;        
        // 生成地盘
        diPan = generateDiPan();
        // 计算直符、直使
        findZhifuZhishi();
        // 转动直符、直使
        turnZhifuZhishi();
        // 八神
        generateBaShen();
        // 天盘
        generateTianPan();
        // 排旬空和马星
        generateXunKongMaxing();
        
        std::cout << "干支:" << NianGan << " " << YueGan << " " << RiGan << " " << ShiGan << std::endl;
        std::cout << "     " << NianZhi << " " << YueZhi << " " << RiZhi << " " << ShiZhi;
        std::cout << "     (天禽星与天芮星同位置)" << std::endl;
        std::cout << "===========================================" << std::endl;
        std::cout << "值符:" << zhiFu << "  值使: " << zhiShi ;
        std::cout << "   [" << m_jieqi << m_yuan << "]";
        if (isYinDun)
        {
            std::cout << "[阴遁" << style << "局]" << std::endl;
        }
        else
        {
            std::cout << "[阳遁" << style << "局]" << std::endl;
        }
        // 准备打印结果
        PrintResult *su = new PrintResult;
        su->m1 = baShenRe;
        su->m2 = jiuXingRe;
        su->m3 = baMenRe;
        su->m4 = tianPan;
        su->m5 = diPan;
        su->m6 = otherRe;

        su->showOne = m_calendar->zhSubstr(m_calendar->lunarDayZhu, 2, 0, 1);
        su->showTwo = m_calendar->zhSubstr(m_calendar->lunarHourZhu, 2, 0, 1);
        su->zhiFu = zhiFu;
        su->zhiShi = zhiShi;
        su->Print();

        delete su;
        su = nullptr;
        // std::cout << "说明：上盘仅为排版测试，内容并不正确。" << std::endl;
        std::string JQ1, JQ2;
        std::string JQ1Time = m_calendar->getJieQiStandardTime(m_year, m_calendar->jieQiOne, JQ1);
        std::string JQ2Time = m_calendar->getJieQiStandardTime(m_year, m_calendar->jieQiTwo, JQ2);
        std::cout << "节气:" << JQ1Time.substr(4, 2) << "月" << JQ1Time.substr(6, 2) << "日 [" << JQ1 << "] "
            << JQ1Time.substr(8, 2) << ":" << JQ1Time.substr(10, 2) << ":" << JQ1Time.substr(12, 2) << std::endl;
        std::cout << "节气:" << JQ2Time.substr(4, 2) << "月" << JQ2Time.substr(6, 2) << "日 [" << JQ2 << "] "
            << JQ2Time.substr(8, 2) << ":" << JQ2Time.substr(10, 2) << ":" << JQ2Time.substr(12, 2) << std::endl;
        std::cout << "===========================================" << std::endl;
    }
}
// 定哪一局
void HQiMen::confirmNumth()
{
    generate();

    std::string currentDate = m_calendar->GetStandardDate(m_year, m_month, m_day);
    if (oneYearData.count(currentDate) > 0)
    {
        std::string re = oneYearData[currentDate];
        m_jieqi = m_calendar->zhSubstr(re, 4, 0, 2);
        std::string cu = m_calendar->zhSubstr(re, 4, 2, 2);

        int currentIndex = m_calendar->sixtyJiaziIndex[cu];
        int futou = (currentIndex / 15) * 15;
        int select = (currentIndex - futou) / 5;
        switch (select)
        {
            case 0:
                m_yuan = "上元";
                break;
            case 1:
                m_yuan = "中元";
                break;
            case 2:
                m_yuan = "下元";
                break;
            default:
                m_yuan = "错误";
        }
        int value = juAndJieQi[m_jieqi];

        if ((value % 10) == 1)
        {
            isYinDun = false;
        }
        else
        {
            isYinDun = true;
        }
        if (m_yuan == "上元")
        {
            style = value / 1000;
        }
        else if (m_yuan == "中元")
        {
            style = (value - ((value / 1000) * 1000)) / 100;
        }
        else
        {
            style = ((value - (value % 10)) / 10) % 10;
        }
    }
    else
    {
        std::cout << "<阴阳遁数据中未找到数据>" << std::endl;
    }
}
// 生成阴遁阳遁表
void HQiMen::generate()
{
    oneYearData.clear();
    std::string daXueRiZhu;
    std::string daXueDate;

    // 1. 获取上一年的大雪日期的日柱
    int preYear = m_year - 1;
    Calendar* su = new Calendar;
    su->SetSolarDate(preYear, 12, 15, 12);
    std::string daxue = "";
    std::string daXueDateTime = su->getJieQiStandardTime(preYear, su->jieQiOne, daxue);
    daXueDate = daXueDateTime.substr(0, 8);
    su->SetSolarDate(preYear, 12, std::stoi(daXueDateTime.substr(6, 2)), 12);
    daXueRiZhu = su->lunarDayZhu;
    delete su;
    su = nullptr;

    // 2.查找大雪节气的符头
    int daxueIndex = m_calendar->sixtyJiaziIndex[daXueRiZhu];
    int futou = (daxueIndex / 15) * 15;
    // 下一个符头的索引
    // int nextFutou = (futou + 15) % 60;
    // 判断是否需要置润
    bool isZhiRun = false;
    if ((daxueIndex - futou) >= 9)
    {
        isZhiRun = true;
    }
    else
    {
        isZhiRun = false;
    }

    int add = daxueIndex;
    std::string nextDate = daXueDate;
    // 先把当前的三元保存进去
    for (int i = 0; i < futou + 15 - daxueIndex; i++)
    {
        std::string nextRiZhu = m_calendar->sixtyJiazi[add];
        oneYearData.insert(std::make_pair(nextDate, "大雪"+nextRiZhu));
        nextDate = m_calendar->GetAfterDayFromDate(nextDate);
        add++;
    }
    // 此时的 nextDate 是下一个节气的符头日期
    std::string startJieQiName;
    if (isZhiRun)
    {
        startJieQiName = "大雪";
    }
    else
    {
        startJieQiName = "冬至";
    }
    int jieqiMutex = 0;
    std::string mangZhongStartZhu = "";
    for (int i = 0; i < 300; i++)
    {
        std::string nextRiZhu = m_calendar->sixtyJiazi[(add) % 60];
        if (jieqiMutex == 15)
        {
            startJieQiName = m_calendar->jieQiInfoIndex[(m_calendar->jieQiInfo[startJieQiName] + 1) % 24];
            if (startJieQiName == "芒种")
            {
                oneYearData.insert(std::make_pair(nextDate, startJieQiName + nextRiZhu));
                mangZhongStartZhu = nextRiZhu;
                break;
            }
            jieqiMutex = 0;
        }
        oneYearData.insert(std::make_pair(nextDate, startJieQiName + nextRiZhu));
        nextDate = m_calendar->GetAfterDayFromDate(nextDate);
        jieqiMutex++;
        add++;
    }

    // 此时 nextDate 是芒种的上元第一天，在这里看看需不需要置润
    std::string mangZhongDate;
    Calendar* suTwo = new Calendar;
    suTwo->SetSolarDate(m_year, 6, 15, 12);
    std::string mangZhong = "";
    std::string mangZhongDateTime = suTwo->getJieQiStandardTime(m_year, suTwo->jieQiOne, mangZhong);
    mangZhongDate = mangZhongDateTime.substr(0, 8);
    
    delete suTwo;
    suTwo = nullptr;

    if (m_calendar->GetDayDiffTwo(mangZhongDate, nextDate) >= 9)
    {
        isZhiRun = true;
    }
    else
    {
        isZhiRun = false;
    }

    // 先把当前的的芒种三元保存进去
    for (int i = 0; i < 14; i++)
    {
        add++;
        nextDate = m_calendar->GetAfterDayFromDate(nextDate);
        std::string nextRiZhu = m_calendar->sixtyJiazi[(add) % 60];
        oneYearData.insert(std::make_pair(nextDate, "芒种" + nextRiZhu));
    }
    if (isZhiRun)
    {
        startJieQiName = "芒种";
    }
    else
    {
        startJieQiName = "夏至";
    }
    jieqiMutex = 0;
    std::string daxueStartZhu = "";
    for (int i = 0; i < 300; i++)
    {
        add++;
        nextDate = m_calendar->GetAfterDayFromDate(nextDate);
        std::string nextRiZhu = m_calendar->sixtyJiazi[(add) % 60];
        if (jieqiMutex == 15)
        {
            startJieQiName = m_calendar->jieQiInfoIndex[(m_calendar->jieQiInfo[startJieQiName] + 1) % 24];
            if (startJieQiName == "大雪")
            {
                oneYearData.insert(std::make_pair(nextDate, startJieQiName + nextRiZhu));
                daxueStartZhu = nextRiZhu;
                break;
            }
            jieqiMutex = 0;
        }
        oneYearData.insert(std::make_pair(nextDate, startJieQiName + nextRiZhu));
        jieqiMutex++;
    }
    // 此时 nextDate 是大雪上元第一天，在这里看看需不需要置润
    Calendar* suThree = new Calendar;
    suThree->SetSolarDate(m_year, 12, 15, 12);
    std::string newDaxueDateTime = suThree->getJieQiStandardTime(m_year, suThree->jieQiOne, mangZhong);
    daXueDate = newDaxueDateTime.substr(0, 8);
    delete suThree;
    suThree = nullptr;

    if (m_calendar->GetDayDiffTwo(daXueDate, nextDate) >= 9)
    {
        isZhiRun = true;
    }
    else
    {
        isZhiRun = false;
    }
    
    // 先把当前的大雪节气排进去
    for (int i = 0; i < 14; i++)
    {
        add++;
        nextDate = m_calendar->GetAfterDayFromDate(nextDate);
        std::string nextRiZhu = m_calendar->sixtyJiazi[(add) % 60];
        oneYearData.insert(std::make_pair(nextDate, "大雪" + nextRiZhu));
    }
    if (isZhiRun)
    {
        startJieQiName = "大雪";
    }
    else
    {
        startJieQiName = "冬至";
    }
    jieqiMutex = 0;

    for (int i = 0; i < 60; i++)
    {
        add++;
        nextDate = m_calendar->GetAfterDayFromDate(nextDate);
        std::string nextRiZhu = m_calendar->sixtyJiazi[(add) % 60];
        if (jieqiMutex == 15)
        {
            startJieQiName = m_calendar->jieQiInfoIndex[(m_calendar->jieQiInfo[startJieQiName] + 1) % 24];
            if (startJieQiName == "立春")
            {
                oneYearData.insert(std::make_pair(nextDate, startJieQiName + nextRiZhu));
                daxueStartZhu = nextRiZhu;
                break;
            }
            jieqiMutex = 0;
        }
        oneYearData.insert(std::make_pair(nextDate, startJieQiName + nextRiZhu));
        jieqiMutex++;
    }
}
// 生成地盘，vector 长度为 9
std::vector<std::string> HQiMen::generateDiPan()
{
    std::vector<std::string> result(9);

    int index = m_calendar->getRemainder((style - 1), 9);
    result.at(index) = "戊";

    // 阴遁阳遁排序不同
    if (isYinDun)
    {
        for (int i = 0; i < 5; i++)
        {
            index--;
            result.at(m_calendar->getRemainder(index, 9)) = m_calendar->tianGan[5 + i];
        }
        for (int i = 0; i < 3; i++)
        {
            index--;
            result.at(m_calendar->getRemainder(index, 9)) = m_calendar->tianGan[3 - i];
        }
    } else {
        for (int i = 0; i < 5; i++)
        {
            index++;
            result.at(index % 9) = m_calendar->tianGan[5 + i];
        }
        for (int i = 0; i < 3; i++)
        {
            index++;
            result.at(index % 9) = m_calendar->tianGan[3 - i];
        }
    }
    return result;
}
// 找直符、直使
void HQiMen::findZhifuZhishi()
{
    std::string hourZhu = m_calendar->lunarHourZhu;
    // 查找旬头
    int index = m_calendar->sixtyJiaziIndex[hourZhu];
    int futou = (index / 10) * 10;
    std::string tmp = m_calendar->sixtyJiazi[futou];
    // 旬头对应的六仪
    std::string tg = liuJia[tmp];
    // 宫的位置
    int tindex = getIndex(diPan, tg);
    // 看直符是谁
    zhiFu = jiuXing[tindex];
    zhiShi = baMen[tindex];
}
 // 查看 data 在 m 中的下标
int HQiMen::getIndex(std::vector<std::string> m, std::string data)
{
    int i = 0;
    std::vector<std::string>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        if (*it == data)
        {
            break;
        }
        i++;
    }
    return i;
}
// 转动直符、直使
void HQiMen::turnZhifuZhishi()
{
    std::string hourTG = m_calendar->zhSubstr(m_calendar->lunarHourZhu, 2, 0, 1);
    if (hourTG == "甲")
    {
        jiuXingRe.assign(jiuXing.begin(), jiuXing.end());
        baMenRe.assign(baMen.begin(), baMen.end());
        return;
    }
    int hourIndex = getIndex(diPan, hourTG);
    int t_index = hourIndex;
    if (t_index == 4)
    {
        t_index = 1;
    }
    std::vector<std::string> result(9);
    std::string t = zhiFu;
    if (zhiFu == "天禽")
    {
        t = "天芮";
    }

    result.at(t_index) = zhiFu;
    int zhiFuIndex = getIndex(jiuXingPaiLie, t);
    int __index[8] = {1, 6, 5, 0, 7, 2, 3, 8};
    int start = 0;
    for (int i = 0; i < 8; i++)
    {
        if (t_index == __index[i])
        {
            break;
        }
        start++;
    }
    // "天蓬", "天任", "天冲", "天辅", "天英", "天芮", "天柱", "天心"
    for (int i = 0; i < 8; i++)
    {
        std::string nextName = jiuXingPaiLie[(++zhiFuIndex) % 8];
        start++;
        result.at(__index[start % 8]) = nextName;
    }
    jiuXingRe = result;  // 至此完成了九星的排列

    // 下面排八门
    std::string hourZhu = m_calendar->lunarHourZhu;
    // 查找旬头
    int index = m_calendar->sixtyJiaziIndex[hourZhu];
    int futou = (index / 10) * 10;
    std::string tmp = m_calendar->sixtyJiazi[futou];
    // 旬头对应的六仪
    std::string tg = liuJia[tmp];
    // 旬头宫的位置
    int tindex = getIndex(diPan, tg);
    // 从 tindex 宫开始向后排列
    int tt = 0;
    if (isYinDun)
    {
        for (int i = 0; i < 9; i++)
        {
            if (m_calendar->sixtyJiazi[futou] == m_calendar->lunarHourZhu)
            {
                break;
            }
            tindex--;
            futou++;
            tt = m_calendar->getRemainder(tindex, 9);
        }
    } else {
        for (int i = 0; i < 9; i++)
        {
            if (m_calendar->sixtyJiazi[futou] == m_calendar->lunarHourZhu)
            {
                break;
            }
            tindex++;
            futou++;
            tt = m_calendar->getRemainder(tindex, 9);
        }
    }

    if (tt == 4)
    {
        tt = 1;
    }
    start = 0;
    // int __index[8] = {1, 6, 5, 0, 7, 2, 3, 8};
    for (int i = 0; i < 8; i++)
    {
        if (tt == __index[i])
        {
            break;
        }
        start++;
    }
    int menIndex = 0;
    // 找出门的下标
    for (int i = 0; i < 8; i++)
    {
        if (baMenPaiLie.at(i) == zhiShi)
        {
            break;
        }
        menIndex++;
    }
    std::vector<std::string> resultBamen(9);
    // "休门", "生门", "伤门", "杜门", "景门", "死门", "惊门", "开门"
    for (int i = 0; i < 8; i++)
    {
        std::string nextName = baMenPaiLie[(menIndex++) % 8];
        resultBamen.at(__index[start % 8]) = nextName;
        start++;
    }
    baMenRe = resultBamen;  // 至此完成了八门的排列
}
// 排八神
void HQiMen::generateBaShen()
{
    // "值符", "腾蛇", "太阴", "六合", "白虎", "玄武", "九地", "九天"
    std::string hourTG = m_calendar->zhSubstr(m_calendar->lunarHourZhu, 2, 0, 1);
    if (hourTG == "甲")
    {
        hourTG = liuJia[m_calendar->lunarHourZhu];
    }
    int hourIndex = getIndex(diPan, hourTG);
    int t_index = hourIndex;
    if (t_index == 4)
    {
        t_index = 1;
    }
    int __index[8] = {1, 6, 5, 0, 7, 2, 3, 8};
    int start = 0;
    for (int i = 0; i < 8; i++)
    {
        if (t_index == __index[i])
        {
            break;
        }
        start++;
    }
    int tmp = 0;
    std::vector<std::string> result(9);
    if (!isYinDun)
    {
        for (int i = 0; i < 8; i++)
        {
            std::string nextName = baShenPaiLie[tmp];
            result.at(__index[start % 8]) = nextName;
            start++;
            tmp++;
        }
    } else {
        for (int i = 0; i < 8; i++)
        {
            std::string nextName = baShenPaiLie[tmp];
            result.at(__index[m_calendar->getRemainder(start, 8)]) = nextName;
            start--;
            tmp++;
        }
    }
    baShenRe = result;
}
// 排天盘
void HQiMen::generateTianPan()
{
    std::vector<std::string> result(9);
    std::string tmp;
    for (int i = 0; i < 9; i++)
    {
        tmp = jiuXing.at(i);
        if (tmp == "天禽")
        {
            tmp = "天芮";
        }
        std::string diPanTmp = diPan.at(i);
        int xingIndex = getIndex(jiuXingRe, tmp);
        if (result.at(xingIndex) != "")
        {
            result.at(xingIndex) = result.at(xingIndex) + diPanTmp;
        } else {
            result.at(xingIndex) = diPanTmp;
        }
    }
    tianPan = result;
}
// 排旬空和马星
void HQiMen::generateXunKongMaxing()
{
    std::string hourZhu = m_calendar->lunarHourZhu;
    // 查找旬头
    int index = m_calendar->sixtyJiaziIndex[hourZhu];
    int xuntou = (index / 10) * 10;
    std::string tmp1 = m_calendar->sixtyJiazi[xuntou + 10];
    std::string tmp2 = m_calendar->sixtyJiazi[xuntou + 11];
    std::string d1 = m_calendar->zhSubstr(tmp1, 2, 1, 1);
    std::string d2 = m_calendar->zhSubstr(tmp2, 2, 1, 1);

    std::vector<std::string> result(9);
    result.at(zhangSheng[d1]) = "空";
    result.at(zhangSheng[d2]) = "空";

    // 马星(由时辰的三合来找)
    std::string d3 = m_calendar->zhSubstr(m_calendar->lunarHourZhu, 2, 1, 1);
    std::string t1 = xiangChong[sanHe[d3]];

    result.at(zhangSheng[t1]) = "马" + result.at(zhangSheng[t1]);

    otherRe = result;
}