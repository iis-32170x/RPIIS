cmake_minimum_required(VERSION 3.22)

project(pivo2)

set(SOURCE_EXE src/test.cpp)

set(SOURCE_LIB src/mnojestvo.cpp)

add_library(mnojestvo STATIC ${SOURCE_LIB})

add_executable(test ${SOURCE_EXE})

target_link_libraries(test gtest gmock pthread mnojestvo)