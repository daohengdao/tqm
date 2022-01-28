#ifndef DEAL_H
#define DEAL_H

#include <string>
#include <string.h>
#include <iostream>
#include <regex>
#include <vector>
#include "calendar.h"

bool IsParaLegal(int argc, char* argv[], std::string& result, bool &isAddEight);
// 显示默认的介绍
void ShowDefaultInfo();
// 参数错误时，提示信息
void ShowNotice();
// 执行未实现的功能时的提示
void ShowOther();
// 检查日期内容是否合法 YYYYMMDDHH
bool IsSolarLegal(std::string date);
// 字符串替换
std::string ReplaceString(std::string data, std::string oldData, std::string newData);
// 字符串分割
void SplitString(const std::string& data, std::string splitString, std::vector<std::string>& result);

#endif

