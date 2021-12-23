#ifndef DEAL_H
#define DEAL_H

#include <string>
#include <string.h>
#include <iostream>
#include <regex>
#include <vector>
#include "calendar.h"
/*
 *  进行参数处理和逻辑判断
 *
 *  本软件命令行参数使用介绍：
 *  【第一个参数介绍：门派确定(x表示功能暂未实现，v表示已实现)】
 *      (x)TQiMen -n  表示年家奇门。
 *      (x)TQiMen -y  表示月家奇门。
 *      (x)TQiMen -r  表示日家奇门。
 *      (v)TQiMen -s  表示时家奇门[置润][转盘法]。
 *  【第二个参数介绍：确定详情（以下以时家奇门[置润][转盘法]为例）】
 *
 *      时家必须传入两个参数，-s 指定日期，-m 指定手动选局。
 *
 *      <传入参数示例>TQiMen -s 0 -m 0 (时家奇门)
 *      [s1=0]表示用当前的时间起局。
 *      [m1=0]表示自动计算第几局。
 *      若 s 后的参数不为0，参数必须按照格式:YYYY-MM-DD-HH-MM-SS(公历)传入
 *      例:TQiMen -s 1990-08-06-12-45-17，表示公历1990年8月6日12点45分17
 *		秒的局(24h制)。
 *      若 m 后的参数不为0，参数必须按照格式: yi8(阴遁8局), ya7(阳遁7局)
 *      例:TQiMen -s 1990-08-06-12-12-45-17 -m yi8 表示公历1990年8月6日
 *      12点的局, 但是使用指定的阴遁八局来起。
 *
 *      说明: -m 的参数 yi 表示阴遁，ya 表示阳遁，后面紧跟的数字指定几局。
*/

/* 判断参数是否合法，如果不合法返回 false，如果合法，结果将参数结果保存到
 * result中，示例格式为: s 1990-08-06-12 yi8（空格隔开）
*/
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

