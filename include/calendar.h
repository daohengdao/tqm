#ifndef LUNAR_H
#define LUNAR_H


#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif // _WIN32

typedef long long int INT64;

class Calendar
{
    /*
     * ********************************************************************
     * ********************************************************************
     * **
     * **   1.【功能】根据公历日期查 农历日期、四柱、节气（精确到秒）
     * **
     * **   2.【重要信息】本程序的四柱是以 <立春> 为界限（精确到秒）
     * **
     * **   3.【支持的时间段】公历 1900-01-31 至 2098-12-31
     * **      此时间段内时间标准与寿星天文历数据一致
     * **
     * **   4.【实现】 因使用跨度和信息很少，因此使用查表法实现
     * **
     * **   5.【接口】内含时间日期处理，和节气日期处理的函数接口可以使用。
     * **      但要注意部分日期处理仅支持上诉日期范围，如节气的日期计算。
     * **
     * **                                                       -- by taynpg
     * *********************************************************************
     * *********************************************************************
    */
    /*
     * 《使用方法》
     *  新建一个 Calendar 对象后
     *  先调用以下函数进行 公历 [年月日时分秒]录入，即可使用其他内容。
     * 
     *  < SetSolarDate >
    */
    /* 本程序的初始化入口函数 */
public:
    // 录入公历日期（同一个对象可以反复调用），如果日期不合法，返回 false。
    // 最后两个参数 分钟 秒钟 默认为 0，可以不填写。若传入的日期当天有节气，则可能会对结果有影响，
    // 若传入的日期当天没有节气，则对结果无影响、因此若日期当日有节气信息，建议传入精确时间。
    bool SetSolarDate(int year, int month, int day, int hour, int min = 0, int second = 0);

    /* 该部分是传入的内容 (用户主要使用的部分) */
public:
    int solarYear = 0;          // 公历年 4 位数字
    int solarMonth = 0;         // 公历月
    int solarDay = 0;           // 公历日
    int solarHour = 0;          // 公历小时
    int solarMin = 0;           // 公历分
    int solarSecond = 0;        // 公历秒

/* 该部分是计算出来的内容 (用户主要使用的部分) */
public:
    int lunarYear = 0;           // 农历年 4 位数字
    int lunarMonth = 0;          // 农历月
    int lunarDay = 0;            // 农历日
    bool isBigMonth = false;     // 农历的月 月大还是月小，(月大 30 天，月小 29 天)。
    bool isLeapMonth = false;    // 当前农历月是否为农历闰月

    std::string lunarYearZhu = "";    // 年柱信息(两个字)，如 甲子
    std::string lunarMonthZhu = "";   // 月柱信息(两个字)，如 甲子
    std::string lunarDayZhu = "";     // 日柱信息(两个字)，如 甲子
    std::string lunarHourZhu = "";    // 时柱信息(两个字)，如 甲子
    std::string jieQiOne = "";        // 本月第一个节气信息，返回格式示例 （04-04-清明-时间-13:12:44）
    std::string jieQiTwo = "";        // 本月第二个节气信息，返回格式示例 （04-19-谷雨-时间-20:01:14）

/* (本程序使用的接口, 用户也可使用，但用户需要自己判断输入的参数内容或格式是否合法) */
public:
    Calendar();
    ~Calendar();

    void Init(); // 初始化成员变量，因该函数需要反复调用，所以单独拿出来。

    // 根据基准日期时间和相差的秒钟算 另一个日期 格式 YYYYMMDDHHMMSS ，相差秒钟分正(向前)负(向后)
    std::string GetDateFromTimeDiffAndBase(const std::string &date, INT64 seconds);

    // 返回一个公历日期的前一天的日期, 格式 YYYYMMDD，未检查输入日期的合法性。
    std::string GetPreDayFromDate(const std::string &date);

    // 返回一个公历日期的后一天的日期, 格式 YYYYMMDD，未检查输入日期的合法性。
    std::string GetAfterDayFromDate(const std::string &date);

    // 判断中间的日期是否在前后两个日期之间 格式 YYYYMMDDHHMMSS
    bool IsDateBetweenAC(const std::string &one, const std::string &two, const std::string &three);

    // 计算两个日期时间之间相差的秒数 参数为 YYYYMMDDHHMMSS
    INT64 GetDateTimeDiffTwo(const std::string &one, const std::string &two);

    // 返回两个时间点的秒数之差 参数都为 HHMMSS
    int GetTimeDiffTwo(const std::string &one, const std::string &two);

    // 判断是否是闰年
    bool IsLeapYear(int year);

    // 让月、日、时、分、秒为个数时首位加 0
    std::string TurnWithZero(long num);

    // 判断时间是否合法 HHMMSS
    bool IsTimeLegal(const std::string &time);

    // 判断日期时间是否合法 YYYYMMDDHHMMSS
    bool IsDateTimeLegal(const std::string &dateTime);

    // 判断公历是否合法 YYYYMMDD
    bool IsSolarLegal(const std::string &date);

    // 返回两个日期之间的天数差 参数为 YYYYMMDD
    int GetDayDiffTwo(const std::string &one, const std::string &two);

    // 返回距离 1900.1.1 的天数 格式 YYYYMMDD
    int GetDayDiffFromBase(const std::string &date);

    // 传入年月日给出标准 YYYYMMDD 格式
    std::string GetStandardDate(int year, int month, int day);

    // 传入标准 YYYYMMDD 格式，返回年月日
    void GetDateFromStandardString(const std::string& datetime, int& year, int& month, int& day);

    // 传入年月日时分秒给出标准 YYYYMMDDHHMMSS 格式
    std::string GetStandardDateTime(int year, int month, int day, int hour, int min, int sec);

    // 传入标准 YYYYMMDDHHMMSS 格式, 返回年月日时分秒
    void GetDateTimeFromStandardString(const std::string &datetime, int &year, int &month, int &day, int &hour, int &min, int &sec);

    // 传入时分秒给出标准 HHMMSS 格式
    std::string GetStandardTime(int hour, int min, int sec);

    // 传入标准 HHMMSS 时间格式返回时分秒
    void GetTimeFromStandardString(const std::string time, int &hour, int &min, int &sec);

    // 给出 YYYYMMDDHHMMSS（包含节气的日期） 和节气名字，返回该节气的下一个节气的日期，和名字，返回格式 YYYYMMDDHHMMSS
    void GetNextJieQiDateTime(const std::string& datetime, const std::string& jieQiName, std::string& nextDatetime, std::string& nextJieQiName);

    // 给出 YYYYMMDDHHMMSS（包含节气的日期） 和节气名字，返回该节气的上一个节气的日期，和名字，返回格式 YYYYMMDDHHMMSS
    void GetPreJieQiDateTime(const std::string& datetime, const std::string& jieQiName, std::string& preDatetime, std::string& preJieQiName);

/* 本程序未使用但个人认为有用的函数 */
public:

    // 获取当前系统日期时间，精确到毫秒 格式 YYYYMMDDHHMMSSMIL
    std::string GetSysDateTimeMill();
    // 返回一个时间到 00:00:00 的秒数 ，输入 HHMMSS
    int GetMiaoDiffToZero(const std::string &time);
    // 根据日期 YYYYMMDD 返回这一天是星期几 0-周日， 1-周一 以此类推
    int GetWeekIndexFromDate(const std::string &date);

/* 表 */
public:
    std::map<int, std::string> sixtyJiazi;         // 序号->查60甲子
    std::map<std::string, int> sixtyJiaziIndex;    // 60甲子->序号
    std::map<std::string, int> jieQiInfo;          // 节气信息->序号
    std::map<int, std::string> jieQiInfoIndex;     // 序号->节气信息
    std::vector<std::string> tianGan;              // 天干信息表
    std::vector<std::string> diZhi;                // 地支信息表
/* 表 */
private:
    std::vector<int> lunarInfo;                    // 查表法的农历信息表
    int* times = NULL;                             // 各节气之间相差的秒数(精确数据，用于计算节气的具体时间)
    std::map<std::string, std::string> wuHu;       // 五虎遁年起月表
    std::map<std::string, std::string> qiShi;      // 日上起时法表


/* 主要是本程序使用 */
public:
    std::string getJiazi(int num);                                 // 传入 offset 返回干支, 0=甲子

     // 将格式为 【04-04-清明-时间-13:12:44】的字符串转成 YYYYMMDDHHMMSS 标准格式，节气名称保存到 jieQi 中
    std::string getJieQiStandardTime(int year, const std::string& time, std::string& jieQi);

    // 对于纯中文（注意不能字符和中文夹杂）的 substr (参数，num 为该字符串有几个中文汉字)
    std::string zhSubstr(const std::string& data, int num, size_t start, size_t length);

    // 对 num 取余，jinZhi 为基数，num 支持负数，结果在 [0, jinZhi-1]内
    unsigned int getRemainder(int num, int jinZhi);                         

/* 主要是本程序使用 */
private:
    int getLunarYearDays(int year);                                // 返回农历 y 年的总天数
    int getLunarLeapDays(int year);                                // 返回农历 y 年闰月的天数
    int getLunarLeapMonth(int year);                               // 返回农历 y 年闰哪个月 1-12 , 没闰返回 0
    int getLunarMonthDays(int year, int month);                    // 返回农历 y 年 m 月的总天数
    int getLunarSTerm(int year, int n, std::string& result);       // 某年的第 n 个节气为几日 (从0小寒起算)

    void getYearMonthZhu();                                        // 计算农历年的 年柱、月柱 (以立春为新年)
    void getHourZhu();                                             // 计算时柱  (该函数要在计算年柱月柱之后执行)
    

    // 给出某年某月的年柱、月柱、返回上一个月的年柱、月柱。并指出所给月份是否是含立春的月份。
    std::string getPreMonthYearMothZhu(int year, int month, const std::string &yearZhu, const std::string &monthZhu, bool isLiChun);

    // 传入公历的年、月、此月的节气、此月的月柱、此年柱 -> 获取该节气的下一个节气的 年、月、节气、月柱、年柱(YYYYMMXXPPYY)
    void getNexJieQiInfo(int &year, int &month, std::string &jieQi, std::string &monthZhu, std::string &yearZhu);

    // 给出年柱，返回下一年的起始月柱， 格式 XX
    std::string getNextYearYearMonthZhu(const std::string &yearZhu);

    // 字符串分割
    void SplitString(const std::string &data, std::string splitString, std::vector<std::string> &result);
};
#endif // LUNAR_H
