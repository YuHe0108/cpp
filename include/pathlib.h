//
// Created by yuhe on 2022/12/5.
//

#ifndef CPP_PATHLIB_H
#define CPP_PATHLIB_H

#include <string>
#include <vector>
#include <iostream>
#include <experimental/filesystem>

#include "common.h"

class PathLib {
public:
    PathLib(const std::string &inputPath);

    std::vector<std::string> IterDir(const std::string &dir);

    static bool FileExist(const std::string &path);

    std::string path; // 路径
    std::string suffix; // 文件的后缀
    std::string stem; // file
    std::string name; // file.txt
    std::string parent;
};

#endif //CPP_PATHLIB_H
