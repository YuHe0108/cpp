// 使用示例：
// Created by yuhe on 2022/11/28.
//

#include <iostream>

#include "image_utils.h"
#include "NumCpp.hpp"

int main() {
    std::shared_ptr<cv::Mat> inputs = std::make_shared<cv::Mat>(cv::imread("/mnt/YuHe/remote_code/2.jpg"));
    auto res = LetterBox(inputs, 224, 224);
    std::cout << (res == nullptr) << std::endl;

    nc::NdArray<float> a = {{1, 2},
                            {3, 4}};
    std::cout << a[0] << std::endl;
    std::cout << a[1] << std::endl;
    std::cout << a[2] << std::endl;
    std::cout << a.shape() << std::endl;

    std::cout << "Done" << std::endl;
    return 1;
}
