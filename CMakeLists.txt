cmake_minimum_required(VERSION 3.31)
project(QtTurorial)

set(CMAKE_CXX_STANDARD 20)

# turn on the settings that automatically convert files into executable CPP codes.
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# set the path to find Qt
set(CMAKE_PREFIX_PATH  "/opt/homebrew/opt/qt")
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# add executable projects
add_executable(001 Tutorials/001intro.cpp)
add_executable(002 Tutorials/002QQLoginSystem.ui Tutorials/002UseUI.cpp)

# link the libraries of Qt to a specified executable project
target_link_libraries(001 PRIVATE Qt6::Widgets)
target_link_libraries(002 PRIVATE Qt6::Widgets)
