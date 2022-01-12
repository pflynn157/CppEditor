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

add_compile_options(-std=c++14)
include_directories("${CMAKE_BINARY_DIR}/src")
include_directories(src highlighter)

add_subdirectory(highlighter)
add_subdirectory(src)

if (UNIX)
    if (APPLE)
    else()
        install(FILES share/cpp-editor.desktop DESTINATION /usr/share/applications)
        install(CODE "execute_process(COMMAND update-desktop-database)")
    endif()
endif()
