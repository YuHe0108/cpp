cmake_minimum_required(VERSION 3.20)
project(cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread) # 多线程

find_package(OpenCV REQUIRED)

include_directories(./include)
include_directories(./include/NumCpp)
include_directories(./include/CppHttplib)
include_directories(./include/nlohmann)


file(GLOB SC_FILES "*.cpp" "*.h")
aux_source_directory(./src SRC_LIST)
add_executable(${PROJECT_NAME} ${SC_FILES} ${SRC_LIST})
target_link_libraries(cpp ${OpenCV_LIBS})

