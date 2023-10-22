project(file-explorer)

add_subdirectory(src)

#if (UNIX)
#	install(FILES share/cpp-explorer.desktop DESTINATION /usr/share/applications)
#	install(CODE "execute_process(COMMAND update-desktop-database)")
#endif()

