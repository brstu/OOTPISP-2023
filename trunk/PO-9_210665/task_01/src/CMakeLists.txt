cmake_minimum_required(VERSION 3.5)
project(po9_210665_task_01  LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
add_executable(po9_210665_task_01
        main.cpp
	mainwindow.cpp
	mainwindow.ui
	gg.cpp
	gg.ui
)
target_link_libraries(po9_210665_task_01  Qt${QT_VERSION_MAJOR}::Widgets)
