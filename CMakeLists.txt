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

if (WIN32)
    find_library(libsettings REQUIRED HINTS C:/Unix/bin)
    find_package(KF5SyntaxHighlighting REQUIRED HINTS C:/Unix/bin)
    find_package(KF5DBusAddons REQUIRED HINTS C:/Unix/bin)
    link_directories(C:/Unix/bin)
else()
    find_package(KF5SyntaxHighlighting REQUIRED)
    find_package(KF5DBusAddons REQUIRED)
endif()

add_compile_options(-std=c++11)
include_directories("${CMAKE_BINARY_DIR}/src")
include_directories(src highlighter)

if (WIN32)
    include_directories(C:/Unix/include)
    include_directories(C:/Unix/include/cpplib)
endif()

add_subdirectory(highlighter)
add_subdirectory(src)

if (UNIX)
    if (APPLE)
    else()
        install(FILES share/cpp-editor.desktop DESTINATION /usr/share/applications)
        install(CODE "execute_process(COMMAND update-desktop-database)")
    endif()
endif()
