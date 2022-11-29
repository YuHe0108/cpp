// 使用示例：
// Created by yuhe on 2022/11/28.
//

#include <iostream>

#include "image_utils.h"

int main() {
    std::shared_ptr<cv::Mat> inputs = std::make_shared<cv::Mat>(cv::imread("/mnt/YuHe/remote_code/2.jpg"));
    auto res = LetterBox(inputs, 224, 224);
    std::cout << (res == nullptr) << std::endl;
    cv::imwrite("/mnt/YuHe/r_img.jpg", *res);
    std::cout << "Done" << std::endl;
    return 1;
}
