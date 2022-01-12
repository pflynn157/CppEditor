cmake_minimum_required(VERSION 3.0.0)
project(CppEditor)

set(GLOBAL_SRC
    global/file_actions.cxx
    global/recent.cxx
    global/slots.cxx
)

set(MENUBAR_SRC
    menubar/editmenu.cxx
    menubar/filemenu.cxx
    menubar/helpmenu.cxx
    menubar/insertmenu.cxx
    menubar/recent_widgets.cxx
    menubar/viewmenu.cxx
)

set(MENUS_SRC
    menus/dock_widget_menu.cxx
    menus/editor_context.cxx
)

set(PROJECT_SRC
    project/project_pane.cxx
    project/project_tree.cxx
)

set(SETTINGS_SRC
    settings/editor_page.cxx
    settings/settings_dialog.cxx
)

set(WINDOWS_SRC
    windows/date_selector.cxx
    windows/subwindow.cxx
)

set(BASE_SRC
    actions.cxx
    cpp_message_widget.cxx
    editor.cxx
    main.cxx
    main_toolbar.cxx
    tabpane.cxx
    window.cxx
    icons.qrc
    rsc.qrc
    icon.cxx
    finder.cxx
)

set(SRC_ALL
    ${ACTIONS_SRC}
    ${GLOBAL_SRC}
    ${IPC_SRC}
    ${MENUBAR_SRC}
    ${MENUS_SRC}
    ${PROJECT_SRC}
    ${SETTINGS_SRC}
    ${WINDOWS_SRC}
    ${BASE_SRC}
)

if (WIN32)
    add_executable(CppEditor WIN32 ${SRC_ALL})
else()
    add_executable(CppEditor ${SRC_ALL})
endif()

target_link_libraries(CppEditor
    Qt5::Core
    Qt5::Widgets
    cppedit_highlighter
)

if (UNIX)
    if (APPLE)
        else()
            install(TARGETS CppEditor DESTINATION /usr/local/bin)
    endif()
endif()
