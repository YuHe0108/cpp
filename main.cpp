// Created by yuhe on 2022/11/28.
#include <atomic>
#include <iostream>
#include <memory>
#include <future>
#include <thread>
#include <fstream>

#include "opencv2/opencv.hpp"
#include <nlohmann/json.hpp>
#include "image_utils.h"
#include "NumCpp.hpp"
#include "httplib.h"
#include "pathlib.h"
#include "common.h"
#include "base64.h"
#include "sqlite3/sqlite3.h"

/*
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
*/
using json = nlohmann::json;

void doGetHi(const httplib::Request &req, httplib::Response &res) {
    std::cout << res.headers.empty() << std::endl;
    res.set_content("hi", "text/plain");
}

void postTest(const httplib::Request &req, httplib::Response &res) {
    std::cout << res.headers.empty() << std::endl;
    std::cout << req.params.size() << std::endl;
    auto content = nlohmann::json::parse(req.body.begin(), req.body.end());
    std::cout << (content.find("a") == content.end()) << std::endl;
    std::cout << content["file_name"] << std::endl;
    std::cout << content["download_url"] << std::endl;
    std::cout << "postTest" << std::endl;
}

int main() {
    /*
    std::shared_ptr<cv::Mat> inputs = std::make_shared<cv::Mat>(cv::imread("/mnt/YuHe/remote_code/2.jpg"));
    auto res = letterBox(inputs, 224, 224);
    std::cout << (res == nullptr) << std::endl;
    */
    /*
    nc::NdArray<float> a = {{1, 2},
                            {3, 4}};
    std::cout << a.shape() << std::endl;
     */
    /*
    std::shared_ptr<Point> task1 = std::make_shared<Point>(Point(1, 2));
    std::shared_ptr<Point> task2 = std::make_shared<Point>(Point(2, 3));
    std::shared_ptr<Point> task3 = std::make_shared<Point>(Point(3, 4));
    task1->Start();
    task2->Start();
    task3->Start();
    */
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
    httplib::Params params{
            {"name", "john"},
            {"note", "coder"}
    }; // params.find("note")->second, 字典结构

    // 编码
    /*
    std::string imgPath = "/mnt/YuHe/remote_code/2.jpg";
    std::ifstream is(imgPath, std::ifstream::in | std::ios::binary);
    is.seekg(0, std::ifstream::end);
    int length = is.tellg();
    is.seekg(0, is.beg);
    char *buffer = new char[length];
    is.read(buffer, length);
    std::string str_encode = aip::base64_encode(buffer, length);
    */
    // 将mat图转换为base64
    /*
    std::vector<uchar> buf;
    cv::Mat image = cv::imread(imgPath);
    cv::imencode(".jpg", image, buf);
    std::string str_encode2 = aip::base64_encode(reinterpret_cast<const char *>(buf.data()), buf.size());
    std::cout << str_encode2 << std::endl;

    int index = imgPath.find_last_of(".");
    std::string extendName = imgPath.substr(index + 1, -1);
    std::cout << extendName << std::endl;

    auto str_img = aip::encode_mat_to_base64(imgPath);
    std::cout << "3" << str_img << std::endl;
    auto str_img2 = aip::encode_mat_to_base64(image, "jpg");
    std::cout << "3" << str_img2 << std::endl;

    std::string value = "jpjp";
    std::cout << "split" << (value.find("a") == value.npos) << std::endl;


    auto res2 = splitString(imgPath, ".");
    if (!res2.empty()) {
        int idx = 0;
        for (const auto &item: res2) {
            std::cout << idx << " " << item << std::endl;
            idx += 1;
        }
    }
    */
    /*
    json inputData;
    inputData["image"] = str_encode;
    std::cout << inputData.find("image").key() << std::endl;
    std::cout << inputData.find("image").value() << std::endl;
    httplib::Client cli("http://10.10.10.158:6666");
    httplib::Headers headers = {
            {"content-type", "application/json"}
    };
    auto res = cli.Post("/AI_Interface/ai_predict", headers, inputData.dump(), "application/json");
     */
    /* pathlib的简单使用
    std::cout << "Start" << std::endl;
    std::string pathRoot = "/mnt/YuHe/remote_code";
    auto pathObj = PathLib(pathRoot);
    auto path3 = pathObj.pathJoin("2.jpg");
    std::cout << path3 << std::endl;
    */
    /*
    std::shared_ptr<PathLib> pathlibObj = std::make_shared<PathLib>(PathLib());
    std::shared_ptr<cv::Mat> img1 = std::make_shared<cv::Mat>(cv::imread(imgPath));
    auto res = calcImageDiff(img1, img1, 20, 7);
    */
    /* 接口的调用
    httplib::Server svr;
    svr.Get("/hi", doGetHi);
    svr.Post("/test", postTest);
    svr.listen("0.0.0.0", 8080);
    */
    std::atomic_int gd{0};
    int num3 = 4;
    std::cout << gd + 4 << std::endl;

    // 创建一个表格
    sqlite3 *sql = NULL; // 一个打开的数据库实例
    const char *path = "test.db";//某个sql文件的路径
    int result = sqlite3_open_v2(path, &sql, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE | SQLITE_OPEN_NOMUTEX | SQLITE_OPEN_SHAREDCACHE, NULL);

    char *errMsg = NULL;
    result = sqlite3_exec(sql, "CREATE TABLE person(name QString, age QInt)", 0, 0, &errMsg);
    std::cout << (result == SQLITE_OK) << std::endl;
    std::cout << *errMsg << std::endl;

    // 插入数据
    const char *sqlSentence = "INSERT INTO person(name, age) VALUES('小明', 222); "; //SQL语句
    sqlite3_stmt *stmt = NULL; //stmt语句句柄
    //进行插入前的准备工作——检查语句合法性, -1代表系统会自动计算SQL语句的长度
    int result2 = sqlite3_prepare_v2(sql, sqlSentence, -1, &stmt, NULL);
    if (result2 == SQLITE_OK) {
        std::clog << "添加数据语句done";
        sqlite3_step(stmt);  //执行该语句
    } else {
        std::clog << "添加数据语句wrong";
    }
    //清理语句句柄，准备执行下一个语句
    sqlite3_finalize(stmt);
    // 增删改查
    sqlite3_close_v2(sql);
    sql = nullptr;


    std::cout << std::system("nvidia-smi") << std::endl;
    std::cout << std::system("pwd") << std::endl;
    std::cout << "Done" << std::endl;
    return 1;
}