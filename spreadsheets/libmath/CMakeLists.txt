project(libmath)

add_compile_options(-std=c++17)

set(SRC
    chain.cpp
	column.cpp
)

add_library(math STATIC ${SRC})

