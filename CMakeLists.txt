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
find_package(Qt6 REQUIRED COMPONENTS Multimedia)

# add executable projects
add_executable(001 Tutorials/001intro.cpp)
add_executable(002 Tutorials/002QQLoginSystem.ui Tutorials/002UseUI.cpp)

add_executable(FirstWidget Projects/FirstWidget/main.cpp Projects/FirstWidget/QQLoginSystem.ui Projects/FirstWidget/QQLoginSystem.cpp Projects/FirstWidget/QQLoginSystem.h)
add_executable(AfterClass Projects/AfterClass/main.cpp Projects/AfterClass/teacher.h Projects/AfterClass/student.h Projects/AfterClass/teacher.cpp Projects/AfterClass/student.cpp)
add_executable(Notebook Projects/Notebook/main.cpp Projects/Notebook/notebook.cpp Projects/Notebook/notebook.ui Projects/Notebook/notebook.h)
add_executable(WarPlane
        Projects/WarPlane/main.cpp Projects/WarPlane/config.h
        Projects/WarPlane/bullet.cpp Projects/WarPlane/bullet.h
        Projects/WarPlane/enemywarplane.cpp Projects/WarPlane/enemywarplane.h
        Projects/WarPlane/exploding.cpp Projects/WarPlane/exploding.h
        Projects/WarPlane/herowarplane.cpp Projects/WarPlane/herowarplane.h
        Projects/WarPlane/mainscene.cpp Projects/WarPlane/mainscene.h
        Projects/WarPlane/map.cpp Projects/WarPlane/map.h
        Projects/WarPlane/res.qrc)

# link the libraries of Qt to a specified executable project
target_link_libraries(001 PRIVATE Qt6::Widgets)
target_link_libraries(002 PRIVATE Qt6::Widgets)

target_link_libraries(FirstWidget PRIVATE Qt6::Widgets)
target_link_libraries(AfterClass PRIVATE Qt6::Widgets)
target_link_libraries(Notebook PRIVATE Qt6::Widgets)
target_link_libraries(WarPlane PRIVATE Qt6::Widgets)
target_link_libraries(WarPlane PRIVATE Qt6::Multimedia)

set(WARPLANE_RES /Projects/WarPlane/res.qrc)
qt_add_resources(WarPlane RESOURCES ${WARPLANE_RES})
