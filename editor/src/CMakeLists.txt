set(GLOBAL_SRC
    global/file_actions.cpp
    global/recent.cpp
    global/slots.cpp
)

set(MENUBAR_SRC
    menubar/editmenu.cpp
    menubar/filemenu.cpp
    menubar/helpmenu.cpp
    menubar/insertmenu.cpp
    menubar/recent_widgets.cpp
    menubar/viewmenu.cpp
)

set(MENUS_SRC
    menus/dock_widget_menu.cpp
    menus/editor_context.cpp
)

set(PROJECT_SRC
    project/project_pane.cpp
    project/project_tree.cpp
)

set(SETTINGS_SRC
    settings/editor_page.cpp
    settings/settings_dialog.cpp
)

set(WINDOWS_SRC
    windows/date_selector.cpp
    windows/subwindow.cpp
)

set(BASE_SRC
    actions.cpp
    cpp_message_widget.cpp
    editor.cpp
    main.cpp
    main_toolbar.cpp
    tabpane.cpp
    window.cpp
    icons.qrc
    rsc.qrc
    icon.cpp
    finder.cpp
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
    Qt6::Core
    Qt6::Widgets
    cppedit_highlighter
)

#if (UNIX)
#    if (APPLE)
#        else()
#            install(TARGETS CppEditor DESTINATION /usr/local/bin)
#    endif()
#endif()

