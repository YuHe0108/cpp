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

std::shared_ptr<cv::Mat> letterBox(const std::shared_ptr<cv::Mat> &inputs, int resizeHeight, int resizedWidth);

std::shared_ptr<cv::Mat> calcImageDiff(const std::shared_ptr<cv::Mat> &input1, const std::shared_ptr<cv::Mat> &input2, int threshold, int kernelSize);

int calcMaskSumVal(const std::shared_ptr<cv::Mat> &mask);

float objInMask(const std::shared_ptr<cv::Mat> &input1, const std::vector<float> &coord);

#endif //CPP_IMAGE_UTILS_H
