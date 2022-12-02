// ?????
// Created by yuhe on 2022/11/28.
//
#include <experimental/filesystem>
#include <iostream>
#include <memory>
#include <future>
#include <thread>

#include "image_utils.h"
#include "NumCpp.hpp"
#include "httplib.h"


class Point;

typedef std::shared_ptr<Point> ptr_point;


class Point : public std::enable_shared_from_this<Point> {
public:
    Point() {
        std::cout << "new" << std::endl;
    }

    Point(int _x, int _y) : x(_x), y(_y) {

        std::cout << "new x y" << std::endl;
    }

    void Start() {
        worker_ = std::make_shared<std::thread>(std::bind(&Point::Test, this));
    }

    ~Point() {
        std::cout << "~Point()" << std::endl;
        if (worker_ && worker_->joinable()) {
            worker_->join();
            worker_ = nullptr;
        }
    }

    ptr_point get_this() {
        return shared_from_this();
    }

    void Test() {
        while (true) {
            std::cout << this->x << " " << this->y << std::endl;
        }
    }

    std::shared_ptr<std::thread> worker_;
private:
    int x;
    int y;
};

void funTest(int a) {
    while (true) {
        std::cout << "fun test a " << a << std::endl;
    }
}


void start() {
    std::future<void> ret1 = std::async(funTest, 1);
    std::future<void> ret2 = std::async(funTest, 2);
}

int main() {
    std::shared_ptr<cv::Mat> inputs = std::make_shared<cv::Mat>(cv::imread("/mnt/YuHe/remote_code/2.jpg"));
    auto res = LetterBox(inputs, 224, 224);
    std::cout << (res == nullptr) << std::endl;

    nc::NdArray<float> a = {{1, 2},
                            {3, 4}};
    std::cout << a.shape() << std::endl;

    std::shared_ptr<Point> task1 = std::make_shared<Point>(Point(1, 2));
    std::shared_ptr<Point> task2 = std::make_shared<Point>(Point(2, 3));
    std::shared_ptr<Point> task3 = std::make_shared<Point>(Point(3, 4));
    task1->Start();
    task2->Start();
    task3->Start();

    /*
    auto worker1 = std::async(std::launch::deferred, &funTest, 2);
    worker1.get();
    auto worker2 = std::async(std::launch::deferred, &funTest, 4);
    worker2.get();

    start();
    std::future<void> ret3 = std::async(funTest, 3);

    auto worker1 = std::make_shared<std::thread>(std::bind(&funTest, 1));
    auto worker2 = std::make_shared<std::thread>(std::bind(&funTest, 2));
    */
    std::cout << "Done" << std::endl;
    return 1;
}
