cmake_minimum_required(VERSION 3.21)
project(GRG11GTestAsAHabit)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib/googletest-release-1.11.0)

include_directories(files tests)

include_directories(lib/googletest-release-1.11.0/googletest/include)
include_directories(lib/googletest-release-1.11.0/googlemock/include)

add_executable(GRG11GTestAsAHabit main.cpp files/objects.cpp headers/objects.h files/strings.cpp headers/strings.h files/maths.cpp headers/maths.h files/collections.cpp headers/collections.h files/arrays.cpp headers/arrays.h tests/objects_tests.cpp tests/strings_tests.cpp tests/maths_tests.cpp tests/collections_tests.cpp tests/arrays_tests.cpp)

target_link_libraries(GRG11GTestAsAHabit gtest gtest_main)
