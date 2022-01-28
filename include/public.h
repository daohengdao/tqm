#include <iostream>
#include <vector>
/*
 * 该头文件保存处理各种问题的类
*/
static std::string version = "V1.0.0";
// 打印九宫格结果的类
// 用法：首先需要赋值给 m1 ~ m6，然后调用 Print()
// m1 - m6 的内容顺序是 坎一，坤二，震三...的顺序。
// 可以指定 showOne showTwo 让结果加上中括号提示
class PrintResult
{

public:

    PrintResult();
    ~PrintResult();
    void Print();  // 打印结果
    void clear(); // 清空内容

public:
    std::vector<std::string> m1;  // 八神
    std::vector<std::string> m2;  // 九星
    std::vector<std::string> m3;  // 八门
    std::vector<std::string> m4;  // 天盘
    std::vector<std::string> m5;  // 地盘
    std::vector<std::string> m6;  // 补充

    std::vector<std::string> result;
    // 需要加中括号提示的两个字体
    std::string showOne = "";
    std::string showTwo = "";
    // 直符、直使 *提示
    std::string zhiFu = "";
    std::string zhiShi = "";
private:
    // 处理一格的内容，参数为第几格
    std::string simpleHandleOne(int index);
    // 处理一格的内容，参数为第几格
    std::string simpleHandleTwo(int index);
    // 处理一格的内容，参数为第几格
    std::string simpleHandleThree(int index);
    // 主处理逻辑
    void run();
    // 判空操作，vector 第几个内容（下标）
    std::string handleOne(int num);
    // 不同字数操作，vector 第几个内容（下标）
    std::string handleTwo(int num);
    // 不同字数操作，vector 第几个内容（下标）
    std::string handleThree(int num);
    // 值符、值使返回的空格不同
    std::string haveZhi(std::string data);
};