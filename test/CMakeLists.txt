add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, /home/giulia/CLionProjects/Programmazione/test/lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include${gtest_SOURCE_DIR})

set(SOURCE_FILES runAllTests.cpp test.cpp)
add_executable(test runAllTests ${SOURCE_FILES})
target_link_libraries(test gtest gtest_main core)