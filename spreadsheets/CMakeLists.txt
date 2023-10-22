project(CppSheets)

include_directories(xlnt/include)
include_directories(libmath)

add_subdirectory(xlnt)
add_subdirectory(libmath)
add_subdirectory(src)
