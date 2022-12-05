//
// Created by yuhe on 2022/11/28.
//

#ifndef CPP_IMAGE_UTILS_H
#define CPP_IMAGE_UTILS_H

#include <cstdio>
#include <cassert>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <experimental/filesystem>

std::shared_ptr<cv::Mat> LetterBox(const std::shared_ptr<cv::Mat> &inputs, const int resizeHeight, const int resizedWidth);

std::string EncodeMat2Base64(const std::string& imgPath);

#endif //CPP_IMAGE_UTILS_H
