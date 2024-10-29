cmake_minimum_required(VERSION 3.28)
project(lw1_Pushko)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3 -Wall -Wextra -Werror")

include_directories(include)

add_library(dictionary SHARED src/dictionary.cc)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include(GoogleTest)

add_executable(dictionary_tests tests/dictionary_tests.cc)
target_link_libraries(dictionary_tests dictionary GTest::GTest GTest::Main)
gtest_discover_tests(dictionary_tests)




#
#add_library(real_matrix SHARED src/real_matrix.cc src/row.cc)
#set_target_properties(real_matrix PROPERTIES LIBRARY_OUTPUT_DIRECTORY ../lib)
#
#enable_testing()
#
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
#include(GoogleTest)
#
#add_executable(real_matrix_tests tests/real_matrix_tests.cc)
#target_link_libraries(real_matrix_tests real_matrix GTest::GTest GTest::Main)
#gtest_discover_tests(real_matrix_tests)
#
#add_executable(row_tests tests/row_tests.cc)
#target_link_libraries(row_tests real_matrix GTest::GTest GTest::Main)
#gtest_discover_tests(row_tests)
