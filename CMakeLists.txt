cmake_minimum_required(VERSION 3.10.0)
project(micro-desktop)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Widgets
    Gui
    Multimedia
	MultimediaWidgets
)

add_compile_options(-std=c++17)

add_subdirectory(editor)
#add_subdirectory(file-explorer)
#add_subdirectory(spreadsheets)
#add_subdirectory(media-player)

