cmake_minimum_required(VERSION 3.17)
project(fileExplorer)

set(CMAKE_CXX_STANDARD 17)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(BOOST_ROOT "/opt/homebrew/opt/boost")
find_package(Boost 1.76.0 COMPONENTS filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
   main.cpp
   resources.qrc
        mainwindow.cpp mainwindow.h mainwindow.ui)

add_executable(fileExplorer ${PROJECT_SOURCES})
target_link_libraries(fileExplorer ${Boost_LIBRARIES} Qt${QT_VERSION_MAJOR}::Widgets)
