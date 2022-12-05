//
// Created by yuhe on 2022/12/5.
//
#include "pathlib.h"

std::vector<std::string> PathLib::IterDir(const std::string &dir) {
    std::vector<std::string> res;
    return res;
}

bool PathLib::FileExist(const std::string &inputPath) {
//    if (!inputPath.empty() && std::experimental::filesystem::exists(inputPath)) return true;
    return false;
}

PathLib::PathLib(const std::string &inputPath) {
    this->path = inputPath;
    auto splitRes = split_string(inputPath, ".");
    if (!splitRes.empty()) {
        this->stem = std::move(splitRes[splitRes.size() - 2]);
        this->suffix = std::move(*splitRes.end());
        this->name = this->stem + "." + this->suffix;
    }
}
