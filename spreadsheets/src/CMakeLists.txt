set(SRC
    rsc.qrc
    icons.qrc
    main.cpp
    tablewidget.cpp
    tablewidget_delegate.cpp
    sheetwidget.cpp
    window.cpp
    maintoolbar.cpp
    tabwidget.cpp
    statusbar.cpp
)

set(ACTIONS_SRC
    actions/file_actions.cpp
    actions/format_actions.cpp
    actions/data_actions.cpp
)

set(DIALOGS_SRC
    dialogs/border_dialog.cpp
)

set(FORMULA_SRC
    formula/math.cpp
    formula/formula_utils.cpp
    formula/math_funcs.cpp
    formula/str_funcs.cpp
)

set(MENU_SRC
    menu/page_menu.cpp
)

set(MENUBAR_SRC
    menubar/filemenu.cpp
    menubar/format_menu.cpp
    menubar/cellmenu.cpp
    menubar/helpmenu.cpp
)

set(PARSER_SRC
    parser/parser.cpp
    parser/xml_parser.cpp
    parser/xlsx_parser.cpp
    parser/csv_parser.cpp
    parser/tinyxml2.cpp
)

set(SRC_ALL
    ${SRC}
    ${ACTIONS_SRC}
    ${DIALOGS_SRC}
    ${FORMULA_SRC}
    ${MENU_SRC}
    ${MENUBAR_SRC}
    ${PARSER_SRC}
)

set(WIN_SRC
    ${SRC_ALL}
    appicon.rc
)

if (WIN32)
    add_executable(CppSheets WIN32 ${WIN_SRC})
elseif(APPLE)
    add_executable(CppSheets MACOSX_BUNDLE ${SRC_ALL})
else()
    add_executable(CppSheets ${SRC_ALL})
endif()

target_link_libraries(CppSheets
    Qt6::Core
    Qt6::Widgets
    xlnt
	math
)

if (UNIX)
    if (APPLE)
        install(TARGETS CppSheets BUNDLE DESTINATION /Applications)
    endif()
endif()

