cmake_minimum_required(VERSION 3.31)
project(QtTurorial)

set(CMAKE_CXX_STANDARD 20)

# set the path to find Qt
set(CMAKE_PREFIX_PATH  "/opt/homebrew/opt/qt")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(QtTurorial Tutorials/001intro.cpp)

# link the libraries of Qt
target_link_libraries(QtTurorial PRIVATE Qt6::Widgets)
