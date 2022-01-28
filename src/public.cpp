#include "public.h"

// 主处理逻辑
void PrintResult::run()
{
    std::string s1 = "";
    std::string sim1 = simpleHandleOne(1);
    std::string sim2 = simpleHandleOne(2);
    std::string sim3 = simpleHandleOne(3);
    s1 = s1 + "|" + sim1 + "|" + sim2 + "|" + sim3 + "|";
    result.push_back(s1);

    std::string s2 = "";
    std::string sim4 = simpleHandleTwo(1);
    std::string sim5 = simpleHandleTwo(2);
    std::string sim6 = simpleHandleTwo(3);
    s2 = s2 + "|" + sim4 + "|" + sim5 + "|" + sim6 + "|";
    result.push_back(s2);

    std::string s3 = "";
    std::string sim7 = simpleHandleThree(1);
    std::string sim8 = simpleHandleThree(2);
    std::string sim9 = simpleHandleThree(3);
    s3 = s3 + "|" + sim7 + "|" + sim8 + "|" + sim9 + "|";
    result.push_back(s3);

    std::string s4 = "";
    std::string sim10 = simpleHandleOne(4);
    std::string sim11 = simpleHandleOne(5);
    std::string sim12 = simpleHandleOne(6);
    s4 = s4 + "|" + sim10 + "|" + sim11 + "|" + sim12 + "|";
    result.push_back(s4);

    std::string s5 = "";
    std::string sim13 = simpleHandleTwo(4);
    std::string sim14 = simpleHandleTwo(5);
    std::string sim15 = simpleHandleTwo(6);
    s5 = s5 + "|" + sim13 + "|" + sim14 + "|" + sim15 + "|";
    result.push_back(s5);

    std::string s6 = "";
    std::string sim16 = simpleHandleThree(4);
    std::string sim17 = simpleHandleThree(5);
    std::string sim18 = simpleHandleThree(6);
    s6 = s6 + "|" + sim16 + "|" + sim17 + "|" + sim18 + "|";
    result.push_back(s6);

    std::string s7 = "";
    std::string sim19 = simpleHandleOne(7);
    std::string sim20 = simpleHandleOne(8);
    std::string sim21 = simpleHandleOne(9);
    s7 = s7 + "|" + sim19 + "|" + sim20 + "|" + sim21 + "|";
    result.push_back(s7);

    std::string s8 = "";
    std::string sim22 = simpleHandleTwo(7);
    std::string sim23 = simpleHandleTwo(8);
    std::string sim24 = simpleHandleTwo(9);
    s8 = s8 + "|" + sim22 + "|" + sim23 + "|" + sim24 + "|";
    result.push_back(s8);

    std::string s9 = "";
    std::string sim25 = simpleHandleThree(7);
    std::string sim26 = simpleHandleThree(8);
    std::string sim27 = simpleHandleThree(9);
    s9 = s9 + "|" + sim25 + "|" + sim26 + "|" + sim27 + "|";
    result.push_back(s9);
}
// 打印结果
void PrintResult::Print()
{
    run();
    std::cout << "===========================================" << std::endl;
    std::cout << result.at(0) << std::endl;
    std::cout << result.at(1) << std::endl;
    std::cout << result.at(2) << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << result.at(3) << std::endl;
    std::cout << result.at(4) << std::endl;
    std::cout << result.at(5) << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << result.at(6) << std::endl;
    std::cout << result.at(7) << std::endl;
    std::cout << result.at(8) << std::endl;
    std::cout << "===========================================" << std::endl;
}
// 不同字数操作，vector 第几个内容（下标）
std::string PrintResult::handleThree(int num)
{
    std::string re = "";
    re = re + "    " + m5.at(num) + "  ";
    return re;
}
// 处理一格的内容，参数为第几格
std::string PrintResult::simpleHandleThree(int index)
{
    std::string re = "";
    std::string space;
    switch (index)
    {
    case 1:
        space = m3.at(3);
        re = re + haveZhi(space) + space + handleThree(3);
        break;
    case 2:
        space = m3.at(8);
        re = re + haveZhi(space) + space + handleThree(8);
        break;
    case 3:
        space = m3.at(1);
        re = re + haveZhi(space) + space + handleThree(1);
        break;
    case 4:
        space = m3.at(2);
        re = re + haveZhi(space) + space + handleThree(2);
        break;
    case 5:
        re = "             ";
        break;
    case 6:
        space = m3.at(6);
        re = re + haveZhi(space) + space + handleThree(6);
        break;
    case 7:
        space = m3.at(7);
        re = re + haveZhi(space) + space + handleThree(7);
        break;
    case 8:
        space = m3.at(0);
        re = re + haveZhi(space) + space + handleThree(0);
        break;
    case 9:
        space = m3.at(5);
        re = re + haveZhi(space) + space + handleThree(5);
        break;
    
    default:
        break;
    }
    return re;
}
// 不同字数操作，vector 第几个内容（下标）
std::string PrintResult::handleTwo(int num)
{
    std::string han = "甲";
    size_t l = han.length();
    std::string re = "";
    std::string t = m4.at(num);
    if (t.length() == l)
    {
        if (t == showOne || t == showTwo)
        {
            re = re + "   [" + t + "] ";
        } else 
        {
            re = re + "    " + t + "  ";
        }
    } else if (t.length() > l) {
        re = re + "    " + t;
    }
    return re;
}

// 判空操作，vector 第几个内容（下标）
std::string PrintResult::handleOne(int num)
{
    std::string re = "";
    std::string han = "甲";
    std::string content = m6.at(num);
    size_t length = han.length();
    if (content.length() == length)
    {
        re = re + "   (" + content + ") ";
    } else if (content.length() == (length * 2)) {
        re = re + "  (" + content + ")";
    } else {
        re = "        ";
    }
    return re;
}
// 处理一格的内容，参数为第几格(从上到下，行优先，从左往右数，1~9)
std::string PrintResult::simpleHandleOne(int index)
{
    std::string re = "";
    std::string space = " ";
    switch (index)
    {
    case 1:
        re = re + space + m1.at(3) + handleOne(3);
        break;
    case 2:
        re = re + space + m1.at(8) + handleOne(8);
        break;
    case 3:
        re = re + space + m1.at(1) + handleOne(1);
        break;
    case 4:
        re = re + space + m1.at(2) + handleOne(2);
        break;
    case 5:
        re = "             ";
        break;
    case 6:
        re = re + space + m1.at(6) + handleOne(6);
        break;
    case 7:
        re = re + space + m1.at(7) + handleOne(7);
        break;
    case 8:
        re = re + space + m1.at(0) + handleOne(0);
        break;
    case 9:
        re = re + space + m1.at(5) + handleOne(5);
        break;
    default:
        break;
    }
    return re;
}
void PrintResult::clear()
{
    m1.clear();
    m2.clear();
    m3.clear();
    m4.clear();
    m5.clear();
    m6.clear();
    result.clear();
}
// 处理一格的内容，参数为第几格
std::string  PrintResult::simpleHandleTwo(int index)
{
    std::string re = "";
    std::string space;
    switch (index)
    {
    case 1:
        space = m2.at(3);
        re = re + haveZhi(space) + space + handleTwo(3);
        break;
    case 2:
        space = m2.at(8);
        re = re + haveZhi(space) + space + handleTwo(8);
        break;
    case 3:
        space = m2.at(1);
        re = re + haveZhi(space) + space + handleTwo(1);
        break;
    case 4:
        space = m2.at(2);
        re = re + haveZhi(space) + space + handleTwo(2);
        break;
    case 5:
        re = re + "      " + m5.at(4) + "     ";
        break;
    case 6:
        space = m2.at(6);
        re = re + haveZhi(space) + space + handleTwo(6);
        break;
    case 7:
        space = m2.at(7);
        re = re + haveZhi(space) + space + handleTwo(7);
        break;
    case 8:
        space = m2.at(0);
        re = re + haveZhi(space) + space + handleTwo(0);
        break;
    case 9:
        space = m2.at(5);
        re = re + haveZhi(space) + space + handleTwo(5);
        break;

    default:
        break;
    }
    return re;
}

PrintResult::PrintResult(/* args */)
{

}
PrintResult::~PrintResult()
{

}
// 值符、值使返回的空格不同
std::string PrintResult::haveZhi(std::string data)
{
    if (data == zhiFu || data == zhiShi)
    {
        return "*";
    } else if ((data == "天芮") && zhiFu == "天禽")
    {
        return "*";
    } else {
        return " ";
    }
}
// void printNine()
// {
//     // 一个中文字符占两个字符位置
//     std::cout << "==========================================" << std::endl;
//     std::cout << "| 六合        | 太阴        | 腾蛇       |" << std::endl;
//     std::cout << "| 天心    己  | 天蓬   [丁] | 天任   乙  |" << std::endl;
//     std::cout << "| 景门    辛  | 死门    丙  | 惊门   癸  |" << std::endl;
//     std::cout << "==========================================" << std::endl;
//     std::cout << "| 白虎   (空) |             | 值符       |" << std::endl;
//     std::cout << "| 天柱    戊  |      庚     | 天冲   壬  |" << std::endl;
//     std::cout << "| 杜门    壬  |             | 开门   戊  |" << std::endl;
//     std::cout << "==========================================" << std::endl;
//     std::cout << "| 玄武   (马) | 九地        | 九天       |" << std::endl;
//     std::cout << "| 天芮    癸庚| 天英    丙  | 天辅   辛  |" << std::endl;
//     std::cout << "| 伤门    乙  | 生门    丁  | 休门   己  |" << std::endl;
//     std::cout << "==========================================" << std::endl;
// }