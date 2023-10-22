cmake_minimum_required(VERSION 3.10.0)
project(micro-desktop)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Widgets
    Gui
)

add_compile_options(-std=c++17)

add_subdirectory(file-explorer)
add_subdirectory(spreadsheets)

