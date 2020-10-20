cmake_minimum_required(VERSION 3.17)
project(byte_swapper)

set(CMAKE_CXX_STANDARD 20)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)

find_package(Qt5Widgets REQUIRED)

set(SOURCES main.cpp MainWindow.cpp swap_sequence.cpp swaps.cpp)
set(HEADERS consts.h MainWindow.h swap_sequence.h swaps.h)

#add_executable(byte_swapper main.cpp MainWindow.cpp MainWindow.h consts.h swap_sequence.cpp swap_sequence.h)
add_executable(byte_swapper ${HEADERS} ${SOURCES})

target_link_libraries(byte_swapper Qt5::Widgets)
