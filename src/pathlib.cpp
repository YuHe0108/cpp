//
// Created by yuhe on 2022/12/5.
//
#include "pathlib.h"

std::vector<std::string> PathLib::IterDir(const std::string &dir) { // 遍历this.path下的文件和目录
    std::vector<std::string> res;
    this->path;
    return res;
}

bool PathLib::FileExist(const std::string &inputPath) {
    std::fstream _file;
    _file.open(inputPath.c_str(), std::ios::in);
    if (!_file) return false;
    return true;
}

PathLib::PathLib(const std::string &inputPath) { // 对象初始化, 并赋值fileName等信息
    this->path = inputPath;

    if (inputPath.find('/') != std::string::npos) this->sepCharacter = '/';

    auto splitBasedSep = split_string(inputPath, this->sepCharacter);
    this->parent = ""; // 父目录的路径
    this->name = std::move(splitBasedSep.back());
    for (auto item: splitBasedSep) {
        if (!item.empty()) this->parent += this->sepCharacter + std::move(item);
    }
    if (!this->name.empty()) {
        auto splitFileName = split_string(this->name, ".");
        this->stem = std::move(*splitFileName.begin());
        if (splitFileName.size() == 2) this->suffix = std::move(splitFileName.back());
    }
}

std::string PathLib::PathJoin(const std::string &inputPath) { // 路径拼接
    this->path += this->sepCharacter + inputPath;
    return this->path;
}
