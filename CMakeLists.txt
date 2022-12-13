cmake_minimum_required(VERSION 3.20)
project(cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -pthread) # 多线程

include_directories(
        ./include
        ./include/NumCpp
        ./include/CppHttplib
        ./include/nlohmann
        ./include/sqlite3
        ./deps/opencv/include/
        ./deps/spdlog/
)

link_directories(
        ${PROJECT_SOURCE_DIR}/include/sqlite3/lib/
        ${PROJECT_SOURCE_DIR}/deps/opencv/lib/
)

set(BASE_LIBRARIES opencv_world sqlite3 stdc++fs)

file(GLOB SC_FILES "*.cpp" "*.h" "*.c")
aux_source_directory(./src SRC_LIST)

add_executable(${PROJECT_NAME} ${SC_FILES} ${SRC_LIST})
target_link_libraries(cpp ${BASE_LIBRARIES})

