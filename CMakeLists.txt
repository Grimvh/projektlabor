cmake_minimum_required(VERSION 3.1)
project (sorting-algorithm-tester)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 14)

set(QT_DIR /home/gulyas/Qt/5.13.1/gcc_64)

find_package(Qt5 COMPONENTS Core REQUIRED HINTS ${QT_DIR})

include_directories(.)

file(GLOB sources "*.cpp")
add_executable(sorting-algorithm-tester ${sources})

target_link_libraries(sorting-algorithm-tester Qt5::Core)
