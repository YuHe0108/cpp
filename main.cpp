#include <iostream>
#include <memory>
#include <future>
#include <thread>
#include <fstream>
#include <cstdio>
#include <atomic>

#include "opencv2/opencv.hpp"
#include "nlohmann/json.hpp"
#include "sqlite3/sqlite3.h"
#include "image_utils.h"
#include "NumCpp.hpp"
#include "httplib.h"
#include "pathlib.h"
#include "common.h"
#include "base64.h"


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

//int main() {
//    /*
//    std::shared_ptr<cv::Mat> inputs = std::make_shared<cv::Mat>(cv::imread("/mnt/YuHe/remote_code/2.jpg"));
//    auto res = letterBox(inputs, 224, 224);
//    std::cout << (res == nullptr) << std::endl;
//    */
//    /*
//    nc::NdArray<float> a = {{1, 2},
//                            {3, 4}};
//    std::cout << a.shape() << std::endl;
//     */
//    /*
//    std::shared_ptr<Point> task1 = std::make_shared<Point>(Point(1, 2));
//    std::shared_ptr<Point> task2 = std::make_shared<Point>(Point(2, 3));
//    std::shared_ptr<Point> task3 = std::make_shared<Point>(Point(3, 4));
//    task1->Start();
//    task2->Start();
//    task3->Start();
//    */
//    /*
//    auto worker1 = std::async(std::launch::deferred, &funTest, 2);
//    worker1.get();
//    auto worker2 = std::async(std::launch::deferred, &funTest, 4);
//    worker2.get();
//
//    start();
//    std::future<void> ret3 = std::async(funTest, 3);
//
//    auto worker1 = std::make_shared<std::thread>(std::bind(&funTest, 1));
//    auto worker2 = std::make_shared<std::thread>(std::bind(&funTest, 2));
//    */
//    httplib::Params params{
//            {"name", "john"},
//            {"note", "coder"}
//    }; // params.find("note")->second, ????????????
//
//    // ??????
//    /*
//    std::string imgPath = "/mnt/YuHe/remote_code/2.jpg";
//    std::ifstream is(imgPath, std::ifstream::in | std::ios::binary);
//    is.seekg(0, std::ifstream::end);
//    int length = is.tellg();
//    is.seekg(0, is.beg);
//    char *buffer = new char[length];
//    is.read(buffer, length);
//    std::string str_encode = aip::base64_encode(buffer, length);
//    */
//    // ???mat????????????base64
//    /*
//    std::vector<uchar> buf;
//    cv::Mat image = cv::imread(imgPath);
//    cv::imencode(".jpg", image, buf);
//    std::string str_encode2 = aip::base64_encode(reinterpret_cast<const char *>(buf.data()), buf.size());
//    std::cout << str_encode2 << std::endl;
//
//    int index = imgPath.find_last_of(".");
//    std::string extendName = imgPath.substr(index + 1, -1);
//    std::cout << extendName << std::endl;
//
//    auto str_img = aip::encode_mat_to_base64(imgPath);
//    std::cout << "3" << str_img << std::endl;
//    auto str_img2 = aip::encode_mat_to_base64(image, "jpg");
//    std::cout << "3" << str_img2 << std::endl;
//
//    std::string value = "jpjp";
//    std::cout << "split" << (value.find("a") == value.npos) << std::endl;
//
//
//    auto res2 = splitString(imgPath, ".");
//    if (!res2.empty()) {
//        int idx = 0;
//        for (const auto &item: res2) {
//            std::cout << idx << " " << item << std::endl;
//            idx += 1;
//        }
//    }
//    */
//    /*
//    json inputData;
//    inputData["image"] = str_encode;
//    std::cout << inputData.find("image").key() << std::endl;
//    std::cout << inputData.find("image").value() << std::endl;
//    httplib::Client cli("http://10.10.10.158:6666");
//    httplib::Headers headers = {
//            {"content-type", "application/json"}
//    };
//    auto res = cli.Post("/AI_Interface/ai_predict", headers, inputData.dump(), "application/json");
//     */
//    /* pathlib???????????????
//    std::cout << "Start" << std::endl;
//    std::string pathRoot = "/mnt/YuHe/remote_code";
//    auto pathObj = PathLib(pathRoot);
//    auto path3 = pathObj.pathJoin("2.jpg");
//    std::cout << path3 << std::endl;
//    */
//    /*
//    std::shared_ptr<PathLib> pathlibObj = std::make_shared<PathLib>(PathLib());
//    std::shared_ptr<cv::Mat> img1 = std::make_shared<cv::Mat>(cv::imread(imgPath));
//    auto res = calcImageDiff(img1, img1, 20, 7);
//    */
//    /* ???????????????
//    httplib::Server svr;
//    svr.Get("/hi", doGetHi);
//    svr.Post("/test", postTest);
//    svr.listen("0.0.0.0", 8080);
//    */
//    std::atomic_int gd{0};
//    int num3 = 4;
//    std::cout << gd + 4 << std::endl;
//
//    std::cout << std::system("nvidia-smi") << std::endl;
//    std::cout << std::system("pwd") << std::endl;
//    std::cout << "Done" << std::endl;
//    return 1;
//}

/*
int main() {
    // ???????????????????????????
    sqlite3 *sql = NULL; // ??????????????????????????????
    const char *path = "test.db";//??????sql???????????????
    int result = sqlite3_open_v2(path, &sql, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE | SQLITE_OPEN_NOMUTEX | SQLITE_OPEN_SHAREDCACHE, NULL);

    // ???????????????
    char *errMsg = NULL;
    result = sqlite3_exec(sql, "CREATE TABLE person(name QString, age QInt)", 0, 0, &errMsg);
    std::cout << (result == SQLITE_OK) << std::endl;
    std::cout << *errMsg << std::endl;

    // ??????????????????
    std::string name = "Joker";
    int value = 100;
    std::string sqlCmd;
    const char *sqlSentence;

    std::stringstream insertQuery;
    insertQuery << "INSERT INTO items (time, ipaddr,username,useradd,userphone,age)"
                   " VALUES ('" << value << "', '" << name << "', '" << name << "', '" << name << "', '" << name << "', " << value << ")";
    std::cout << insertQuery.str() << std::endl;


//    sqlite3_stmt *stmt = NULL; //stmt????????????
//    //?????????????????????????????????????????????????????????, -1???????????????????????????SQL???????????????
//    int result2 = sqlite3_prepare_v2(sql, sqlSentence, -1, &stmt, NULL);
//    if (result2 == SQLITE_OK) {
//        std::cout << "??????????????????done" << std::endl;
//        sqlite3_step(stmt);  //???????????????
//    } else std::cout << "??????????????????wrong" << std::endl;
    // ????????????
//    sqlite3_finalize(stmt); //????????????????????????????????????????????????
    sqlite3_close_v2(sql);
    sql = nullptr;




    std::cout << std::system("pwd") << std::endl;
    std::cout << "Done" << std::endl;
    return 0;
}


*/

template<typename T>
int compare(const T &t1, const T &t2) {
    if (t1 > t2)
        return 1;
    if (t1 == t2)
        return 0;
    if (t1 < t2)
        return -1;
}

template<typename T>
T add(const T &t1, const T &t2) {
    return t1 + t2;
}

int main() {
    // c++ ??????
    int a = 1, b = 2;
    auto res = compare(a, b);

    float k = 1.2, f = 1.3;
    auto res2 = add(k, f);
    std::cout << res2 << std::endl;

    std::string name = "Joy";

    size_t c = 10;
    std::cout << sizeof(size_t) << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(unsigned long) << std::endl;

    std::cout << "Done" << std::endl;
    return 0;
}