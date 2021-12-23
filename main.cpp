#include <stdio.h>
#include "deal.h"
#include "hqimen.h"

int main(int argc, char** argv)
{
    std::string result;
    bool isAddEight = false;

    // 1.检查读入的参数是否合法
    if (!IsParaLegal(argc, argv, result, isAddEight))
    {
        return 0;
    }
    // result 中有了正确格式的参数
    // std::cout << result << std::endl;

    // 2.进行函数的选择处理
    std::vector<std::string> tmp;
    SplitString(result, " ", tmp);
    std::string select = tmp.at(0);

    // 3.如果是时家奇门置润局转盘法
    if (select == "s")
    {
        HQiMen* qimen = new HQiMen(tmp.at(1), tmp.at(2), isAddEight);
        qimen->Run();

        delete qimen;
        qimen = nullptr;
    }
    return 0;
}