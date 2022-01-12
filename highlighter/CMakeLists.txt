cmake_minimum_required(VERSION 3.0.0)
project(CppEditor_highlighter)

set(SRC
    language/lua_lang.cpp
    language/cpp_lang.cpp
    language/vhdl_lang.cpp
    language/sh_lang.cpp
    language/js_lang.cpp
    language/php_lang.cpp
    language/qml_lang.cpp
    language/py_lang.cpp
    language/rust_lang.cpp
    language/java_lang.cpp
    language/cs_lang.cpp
    language/go_lang.cpp
    language/v_lang.cpp
    language/sql_lang.cpp
    language/json_lang.cpp
    language/css_lang.cpp
    language/ts_lang.cpp
    language/yaml_lang.cpp
    language/vex_lang.cpp
    language/cmake_lang.cpp
    language/make_lang.cpp
    language/x86_lang.cpp
    language/markdown_lang.cpp

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
