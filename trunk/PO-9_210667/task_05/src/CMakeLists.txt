cmake_minimum_required(VERSION 3.5)
project(lab_5_OOP LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Sql REQUIRED)
add_executable(lab_5_OOP
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)
target_link_libraries(lab_5_OOP PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)