cmake_minimum_required(VERSION 3.0.0)
project(CppEditor_highlighter)

set(SRC
    languagedata.cpp
    qsourcehighliter.cpp
    qsourcehighliterthemes.cpp
)

set(TEST_SRC
    main.cpp
    mainwindow.cpp
    mainwindow.ui
)

add_library(cppedit_highlighter STATIC ${SRC})
add_executable(cppedit_test ${TEST_SRC})

target_link_libraries(cppedit_highlighter
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
)

target_link_libraries(cppedit_test
    cppedit_highlighter
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
)