//
// Created by yuhe on 2022/12/5.
//
#include "pathlib.h"

std::vector<std::string> PathLib::iterDir(const std::string &dir) { // 遍历输入目录下的文件和目录
    std::vector<std::string> res;
    if (!fileSystem::exists(dir)) return res;
    for (auto &item: fileSystem::directory_iterator(dir)) {
        res.push_back(item.path());
    }
    return res;
}

bool PathLib::fileExist(const std::string &path) { // 判断文件是否存在
    std::fstream _file;
    _file.open(path.c_str(), std::ios::in);
    if (!_file) return false;
    return true;
}

PathLib::PathLib(const std::string &inputPath) { // 对象初始化, 并赋值fileName等信息
    this->path = inputPath;

    if (inputPath.find('/') != std::string::npos) this->sepCharacter = '/';
    auto splitBasedSep = splitString(inputPath, this->sepCharacter);
    this->name = std::move(splitBasedSep.back());
    for (auto item: splitBasedSep) {
        if (!item.empty()) this->parent += this->sepCharacter + std::move(item); // 父目录的路径
    }
    if (!this->name.empty()) {
        auto splitFileName = splitString(this->name, ".");
        this->stem = std::move(*splitFileName.begin());
        if (splitFileName.size() == 2) this->suffix = std::move(splitFileName.back());
    }
}

std::string PathLib::pathJoin(const std::string &inputPath) { // 路径拼接
    this->path += this->sepCharacter + inputPath;
    return this->path;
}

void PathLib::createDir(const std::string &inputDir) { // 如果 inputDir 路径不存在则创建
    if (!fileSystem::exists(inputDir)) fileSystem::create_directories(inputDir);
}

