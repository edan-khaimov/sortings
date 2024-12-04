cmake_minimum_required(VERSION 3.29)
project(sorting)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(sorting main.cpp
        PersonComparators.cpp
        UI/mainWindow.cpp
        UI/sortWindow.cpp
        UI/testWindow.cpp
        tests/filesHelper.cpp
        tests/filesHelper.h
        tests/heapSortTest.cpp
        tests/heapSortTest.h
        tests/quickSortTest.cpp
        tests/quickSortTest.h
)

target_link_libraries(sorting PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)