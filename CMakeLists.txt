cmake_minimum_required(VERSION 3.20)
project(cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread) # 多线程

find_package(OpenCV REQUIRED)

include_directories(./include)
include_directories(./include/NumCpp)
include_directories(./include/CppHttplib)
include_directories(./include/nlohmann)
include_directories(./include/sqlite3)

link_directories(${PROJECT_SOURCE_DIR}/include/sqlite3/lib)

file(GLOB SC_FILES "*.cpp" "*.h" "*.c")
aux_source_directory(./src SRC_LIST)
add_executable(${PROJECT_NAME} ${SC_FILES} ${SRC_LIST})
target_link_libraries(cpp ${OpenCV_LIBS} stdc++fs libsqlite3.so)
