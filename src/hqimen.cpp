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
        << "日" << m_hour << "时" << m_min << "分" << m_sec << "秒]" << std::endl;

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
        std::cout << "农历:" << numName[lunarY / 1000] << numName[(lunarY - (lunarY / 1000) * 1000) / 100]
            << numName[((lunarY - (lunarY % 10)) / 10) % 10] << numName[lunarY % 10] << "年 "
            << cnNameMonth[m_calendar->lunarMonth] << cnNameDay[m_calendar->lunarDay]
            << " " << m_calendar->zhSubstr(m_calendar->lunarHourZhu, 2, 1, 2) << "时" << std::endl;
        std::cout << "干支:" << NianGan << " " << YueGan << " " << RiGan << " " << ShiGan << std::endl;
        std::cout << "     " << NianZhi << " " << YueZhi << " " << RiZhi << " " << ShiZhi << std::endl;

        // 以下的内容是属于测试信息
        std::vector<std::string> m1 = {"九地", "腾蛇", "白虎", "六合", "", "九天", "值符", "玄武", "太阴"};
        std::vector<std::string> m2 = {"天英", "天任", "天柱", "天心", "", "天辅", "天冲", "天芮", "天蓬"};
        std::vector<std::string> m3 = {"生门", "惊门", "杜门", "景门", "", "休门", "开门", "伤门", "死门"};
        std::vector<std::string> m4 = {"丙", "乙", "戊", "己", "庚", "辛", "壬", "癸庚", "丁"};
        std::vector<std::string> m5 = {"丁", "癸", "壬", "辛", "", "己", "戊", "乙", "丙"};
        std::vector<std::string> m6 = {"", "", "空", "", "", "", "", "马", ""};

        PrintResult *su = new PrintResult;
        su->m1 = m1;
        su->m2 = m2;
        su->m3 = m3;
        su->m4 = m4;
        su->m5 = m5;
        su->m6 = m6;

        su->showOne = "丁";
        su->showTwo = "辛";
        su->Print();

        delete su;
        su = nullptr;
        std::cout << "说明：上盘仅为排版测试，内容并不正确。" << std::endl;
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

    /***************** 这部分为测试语句 **************/
    std::cout << "[" << m_jieqi << m_yuan << "]";
    if (isYinDun)
    {
        std::cout << "[阴遁" << style << "局]";
    }
    else
    {
        std::cout << "[阳遁" << style << "局]";
    }
    std::cout << "[" << version << "]" << std::endl;
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
