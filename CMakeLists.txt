cmake_minimum_required(VERSION 3.5)
project(Programmazione)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH "/usr/include/x86_64-linux-gnu/qt5/Qt5Widgets")

set(CMAKE_AUTOMOC ON)

add_subdirectory(test)

find_package(Qt5Widgets REQUIRED)


set(SOURCE_FILES main.cpp LoadResources.h LoadResources.cpp File.h File.cpp MainWindow.h MainWindow.cpp Observer.h ConcreteObserver.h Subject.h test/test.cpp test/runAllTests.cpp)
add_executable(Programmazione main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(core Qt5::Widgets)
target_link_libraries(Programmazione core)