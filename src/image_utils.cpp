//
// Created by yuhe on 2022/11/28.
//
#include "image_utils.h"

std::shared_ptr<cv::Mat> letterBox(const std::shared_ptr<cv::Mat> &inputs, const int resizeHeight, const int resizedWidth) {
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

std::shared_ptr<cv::Mat> calcImageDiff(const std::shared_ptr<cv::Mat> &input1,
                                       const std::shared_ptr<cv::Mat> &input2,
                                       int threshold,
                                       int kernelSize) {
    cv::Mat res;
    auto kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(kernelSize, kernelSize));
    cv::absdiff(*input1, *input2, res);
    cv::cvtColor(res, res, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(res, res, cv::Size(kernelSize, kernelSize), 0.0);
    cv::dilate(res, res, kernel);
    cv::threshold(res, res, threshold, 255, cv::THRESH_BINARY);
    return std::make_shared<cv::Mat>(res);
}

int calcMaskSumVal(const std::shared_ptr<cv::Mat> &mask) {
    int sum_val = (int) cv::sum(*mask)[0]; // 计算mask中非0的像素的数量
    if (mask->channels() > 1) sum_val /= mask->channels();
    double min_val, max_val;
    cv::minMaxLoc(*mask, &min_val, &max_val, nullptr, nullptr);
    if (max_val > 1) sum_val /= 255;
    return sum_val;
}

float objInMask(const std::shared_ptr<cv::Mat> &input1, const std::vector<float> &coord) {//判断coord的百分之多少在input中
    float x = coord[0], y = coord[1], w = coord[2], h = coord[3];
    int imgHeight = input1->rows, imgWidth = input1->cols;
    int x1_ = int(x * (float) imgWidth), y1_ = int(y * (float) imgHeight);
    int w_ = int(w * (float) imgWidth), h_ = int(h * (float) imgHeight);
    auto part = cv::Mat(*input1, cv::Rect(x1_, y1_, w_, h_));
    auto partVal = (float) calcMaskSumVal(input1);
    return partVal / (float) w_ / (float) h_;
}

