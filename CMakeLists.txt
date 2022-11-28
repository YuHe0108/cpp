cmake_minimum_required(VERSION 3.10)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

include_directories(./include)
file(GLOB SC_FILES "*.cpp" "*.h")
aux_source_directory(./src SRC_LIST)
add_executable(${PROJECT_NAME} ${SC_FILES} ${SRC_LIST})
target_link_libraries(cpp ${OpenCV_LIBS})

