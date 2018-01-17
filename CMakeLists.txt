cmake_minimum_required(VERSION 3.0.0)
project(CppEditor)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS
    Core
    Widgets
    Gui
)

find_package(KF5SyntaxHighlighting REQUIRED)
find_package(KF5DBusAddons REQUIRED)

find_library(libsettings REQUIRED)

add_compile_options(-std=c++11)
include_directories("${CMAKE_BINARY_DIR}/src")

add_subdirectory(src)
