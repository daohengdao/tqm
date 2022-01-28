#include "deal.h"

// 参数错误时，提示信息
void ShowNotice()
{
    std::cout << "帮助信息:直接执行程序而不给任何参数查看帮助，然后给出正确的命令格式。" << std::endl;
}

// 执行未实现的功能时的提示
void ShowOther()
{
    std::cout << "你好，该功能开发中......" << std::endl;
}

/* 判断参数是否合法，如果不合法返回 false，如果合法，结果将参数结果保存到
 * result中，result格式为: s1 1990-08-06-12 yi8（空格隔开）
*/
bool IsParaLegal(int argc, char* argv[], std::string& result, bool& isAddEight)
{
    result = "";

    if (argc == 1)
    {
        ShowDefaultInfo();
        return false;
    }
    if (argc == 2)
    {
        if ((strcmp(argv[1], "-s")) == 0)
        {
            ShowNotice();
            return false;
        }
        if ((strcmp(argv[1], "-n")) == 0)
        {
            ShowOther();
            return false;
        }
        if ((strcmp(argv[1], "-y")) == 0)
        {
            ShowOther();
            return false;
        }
        if ((strcmp(argv[1], "-r")) == 0)
        {
            ShowOther();
            return false;
        }
        ShowNotice();
        return false;
    }
    if (argc == 3 || argc == 4 ||  argc > 7)
    {
        isAddEight = true;
        ShowNotice();
        return false;
    }
    if (argc == 6)
    {
        if ((strcmp(argv[5], "-a") == 0))
        {
            isAddEight = true;
        }
        else
        {
            ShowNotice();
        }
    }
    if ((strcmp(argv[1], "-s") == 0) && (strcmp(argv[3], "-m") == 0))
    {
        // 使用当前时间
        if (strcmp(argv[2], "0") == 0)
        {
            if (strcmp(argv[4], "0") == 0)
            {
                result = "s 0 0";
                return true;
            }
            else
            {
                std::regex pattern("y[ia]{1}[123456789]{1}");
                if (std::regex_match(argv[4], pattern))
                {
                    std::string t = argv[4];
                    result = "s 0 " + t;
                }
                else
                {
                    std::cout << "请给 m1 传入正确格式的参数。" << std::endl;
                    ShowNotice();
                    return false;
                }
            }
        }
        else
        {
            std::regex pattern("[0123456789]{4}-[0123456789]{2}-[0123456789]{2}-[0123456789]{2}-[0123456789]{2}-[0123456789]{2}");
            std::regex pattern2("[0123456789]{4}-[0123456789]{2}-[0123456789]{2}-[0123456789]{2}");
            // 初步验证参数格式是否满足 yyyy-mm-dd-hh-mm-ss
            if (std::regex_match(argv[2], pattern) || std::regex_match(argv[2], pattern2))
            {
                std::string t = argv[2];
                std::string tp = ReplaceString(t, "-", "");


                if (tp.size() == 10)
                {
                    t = t + "-00-00";
                    tp = tp + "0000";
                }

                Calendar* tmp = new Calendar;

                if (tmp->IsDateTimeLegal(tp))
                {
                    if (strcmp(argv[4], "0") == 0)
                    {
                        result = "s " + t + " 0";
                        return true;
                    }
                    else
                    {
                        std::regex pattern("y[ia]{1}[123456789]{1}");
                        if (std::regex_match(argv[4], pattern))
                        {
                            std::string t1 = argv[2];
                            std::string t2 = argv[4];
                            result = "s " + t1 + " " + t2;
                        }
                        else
                        {
                            std::cout << "请给 m1 传入正确格式的参数。" << std::endl;
                            ShowNotice();
                            return false;
                        }
                    }
                    result = "s " + t + " 0";
                    return true;
                }
                else
                {
                    std::cout << "\n输入的日期格式不正确。\n" << std::endl;
                    return false;
                }
                delete tmp;
                tmp = nullptr;

            }
            else
            {
                std::cout << "请给 s1 传入正确格式的参数。" << std::endl;
                ShowNotice();
                return false;
            }
        }

    } else {
        std::cout << "请传入正确格式的参数或命令。" << std::endl;
        ShowNotice();
        return false;
    }

    return true;
}

// 显示默认的介绍
void ShowDefaultInfo()
{
    std::cout << "******************************************************************" << std::endl;
    std::cout << "【时家奇门遁甲tqm】\n" << std::endl;
    std::cout << "功能:本地离线排盘工具，使用转盘-超接置润法。" << std::endl;
    std::cout << "参数介绍: (-s -m 必须要有且顺序不能颠倒)" << std::endl;
    std::cout << "本命令行程序必须传入两个参数，-s 指定日期，-m 指定手动选局。\n" << std::endl;
    std::cout << "<传入参数示例>tqm -s 0 -m 0" << std::endl;
    std::cout << "其中 s 的值为 0 则用当前时间起局，m 的值为 0 则自动计算第几局。" << std::endl;
    std::cout << "若 s 后的参数不为 0，则参数的格式为(公历24小时制):" << std::endl;
    std::cout << "YYYY-MM-DD-HH-MM-SS 或 YYYY-MM-DD-HH(某数字若为个位数前面需补0)。" << std::endl;
    std::cout << "若 m 后的参数不为0，参数的示例格式: yi8(阴遁8局), ya7(阳遁7局)。" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "说明1: 如果自动获取的时间慢了8小时，最后面添加 -a 参数补正。" << std::endl;
    std::cout << "说明2: 时间跨度(1901-01-01-00-00-00 到 2098-12-31-23-59-59)" << std::endl;
    std::cout << "https://gitee.com/taynpg/tqm" << std::endl;
    std::cout << "                                                          --taynpg" << std::endl;
    std::cout << "******************************************************************" << std::endl;
}


// 检查日期内容是否合法 YYYYMMDDHH
bool IsSolarLegal(std::string date)
{
    int hour = std::stoi(date.substr(8, 2));

    if (hour < 0 || hour > 24)
    {
        return false;
    }

    Calendar ca;
    std::string check = date.substr(0, 8);
    bool result = ca.IsSolarLegal(check);
    return result;
}

// 字符串替换
std::string ReplaceString(std::string data, std::string oldData, std::string newData)
{
    std::string r = data;
    while (true)
    {
        std::string::size_type pos(0);
        if ((pos = r.find(oldData)) != std::string::npos)
        {
            r.replace(pos, oldData.length(), newData);
        }
        else
        {
            break;
        }
    }
    return r;
}
// 字符串分割
void SplitString(const std::string& data, std::string splitString, std::vector<std::string>& result)
{
    result.clear();
    std::string sCopy = data;
    size_t iPosEnd = 0;
    while (true)
    {
        iPosEnd = sCopy.find(splitString);
        if (iPosEnd == (size_t)-1)
        {
            result.push_back(sCopy);
            break;
        }
        result.push_back(sCopy.substr(0, iPosEnd));
        sCopy = sCopy.substr(iPosEnd + 1);
    }
}
