set(BASE_SRC
	actions.cpp
	control.cpp
	main.cpp
	seekbar.cpp
	tray.cpp
	videopane.cpp
	videopane_menu.cpp
	window.cpp
	icons.qrc
	rsc.qrc
)

set(MENUBAR_SRC
	menubar/editmenu.cpp
	menubar/filemenu.cpp
	menubar/helpmenu.cpp
	menubar/recent.cpp
	menubar/recent_action.cpp
	menubar/viewmenu.cpp
)

set(PLAYLIST_SRC
	playlist/listwidget.cpp
	playlist/playlist.cpp
	playlist/settingswidget.cpp
)

set(SETTINGS_SRC
	settings/settings_dialog.cpp
	settings/settings_dialog.ui
)

set(SRC
	${BASE_SRC}
	${MENUBAR_SRC}
	${PLAYLIST_SRC}
	${SETTINGS_SRC}
)

set(WIN_SRC
    ${SRC}
    appicon.rc
)

if (WIN32)
    add_executable(CppMediaPlayer WIN32 ${WIN_SRC})
else()
	add_executable(CppMediaPlayer ${SRC})
endif()

target_link_libraries(CppMediaPlayer
	Qt6::Core
	Qt6::Widgets
	Qt6::Gui
	Qt6::Multimedia
	Qt6::MultimediaWidgets
) 

#install(TARGETS CppMediaPlayer DESTINATION /usr/local/bin)

