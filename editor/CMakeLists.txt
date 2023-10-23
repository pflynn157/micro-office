project(CppEditor)

include_directories(src highlighter)

add_subdirectory(highlighter)
add_subdirectory(src)

#if (UNIX)
#    if (APPLE)
#    else()
#        install(FILES share/cpp-editor.desktop DESTINATION /usr/share/applications)
#        install(CODE "execute_process(COMMAND update-desktop-database)")
#    endif()
#endif()

