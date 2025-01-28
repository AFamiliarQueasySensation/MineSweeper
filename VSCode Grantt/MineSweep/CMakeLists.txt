cmake_minimum_required(VERSION 3.25)

project(MineSweep LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_PREFIX_PATH "C:/Qt/6.8.1/mingw_64/lib/cmake/Qt6")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)


#fmt
include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.1.1
)

FetchContent_MakeAvailable(fmt)



add_executable(MineSweep 

    src/mainwindow.ui
    src/mainwindow.cpp
    src/main.cpp
    src/pushbutton.cpp
    

)
target_link_libraries(MineSweep PRIVATE fmt::fmt Qt6::Core Qt6::Gui Qt6::Widgets)