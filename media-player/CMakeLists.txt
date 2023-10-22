project(CppMediaPlayer)

add_subdirectory(src)

#if (UNIX)
#	install(FILES share/cpp-media-player.desktop DESTINATION /usr/share/applications)
#	install(CODE "execute_process(COMMAND update-desktop-database)")
#endif()

