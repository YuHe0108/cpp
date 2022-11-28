//
// Created by yuhe on 2022/11/28.
//

#ifndef CPP_IMAGE_UTILS_H
#define CPP_IMAGE_UTILS_H

#include <iostream>
#include <opencv2/opencv.hpp>
#include <experimental/filesystem>

std::shared_ptr<cv::Mat> letterBox(std::shared_ptr<cv::Mat> inputs);

#endif //CPP_IMAGE_UTILS_H
