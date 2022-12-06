//
// Created by yuhe on 2022/12/5.
//

#ifndef CPP_PATHLIB_H
#define CPP_PATHLIB_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <experimental/filesystem>

#include "common.h"

namespace fileSystem = std::experimental::filesystem;

class PathLib {
public:
    PathLib() = default;

    PathLib(const std::string &inputPath);

    static std::vector<std::string> iterDir(const std::string &dir);

    static bool fileExist(const std::string &path);

    std::string pathJoin(const std::string &inputPath);

    static void createDir(const std::string &inputDir);

    std::string path; // 路径
    std::string suffix; // 文件的后缀
    std::string stem; // file
    std::string name; // file.txt
    std::string parent;
    std::string sepCharacter = "\\"; // 路径的分隔符
};

#endif //CPP_PATHLIB_H
