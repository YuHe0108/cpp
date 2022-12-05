//
// Created by yuhe on 2022/12/2.
//
#include "common.h"

std::vector<std::string> split_string(const std::string& str, const std::string& val) {
    std::vector<std::string> res;
    std::vector<int> splitIdx; // 需要切分的位置

    // 复制一份字符串
    std::string cpStr = str;
    // 匹配、切分
    while (cpStr.find(val) != std::string::npos) {
        auto idx = cpStr.find(val);
        res.push_back(cpStr.substr(0, idx));
        cpStr = cpStr.substr(idx + val.size(), -1);
    }
    if (!cpStr.empty()) res.push_back(cpStr);
    return res;
}

std::string copy_string(const std::string &str){
    // 深拷贝字符串
    const char *source = str.c_str();
    char res[str.size()];
    strcpy(res, source);
    std::string cpStr(res); // 转换为字符串类型
    return res;
}