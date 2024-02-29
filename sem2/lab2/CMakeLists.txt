cmake_minimum_required(VERSION 3.26)
project(laba2)

set(CMAKE_CXX_STANDARD 17)

add_executable(laba2 main.cpp Header.h
        test1.cpp
        test2.cpp)

add_subdirectory(thirdparty/google_tests)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests
add_executable(test1 test1.cpp )
target_link_libraries(test1 gtest gtest_main)

add_executable(test2 test2.cpp )
target_link_libraries(test2 gtest gtest_main)


