//
// Created by yuhe on 2022/11/28.
//
#include "image_utils.h"

std::shared_ptr<cv::Mat> LetterBox(const std::shared_ptr<cv::Mat> &inputs, const int resizeHeight, const int resizedWidth) {
    int inputHeight = inputs->rows, inputWidth = inputs->cols;

    float wScale = (float) resizedWidth / (float) inputWidth;
    float hScale = (float) resizeHeight / (float) inputHeight;
    auto minScale = std::min(wScale, hScale);
    auto rHeight = (int) (minScale * (float) inputHeight);
    auto rWidth = (int) (minScale * (float) inputWidth);

    cv::Mat res;
    cv::resize(*inputs, res, cv::Size(rWidth, rHeight));
    int wDiff = resizedWidth - rWidth, hDiff = resizeHeight - rHeight;
    cv::copyMakeBorder(res, res, (hDiff / 2), (hDiff / 2), (wDiff / 2), (wDiff / 2),
                       cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));
    return std::make_shared<cv::Mat>(res);
}