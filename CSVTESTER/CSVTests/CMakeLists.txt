cmake_minimum_required(VERSION 3.10)
project(CSVTests)

set(CMAKE_CXX_STANDARD 17)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(third_party/googletest)

add_executable(CSVTests test.cpp)
target_link_libraries(CSVTests gtest_main CSVReaderLib)

enable_testing()
add_test(NAME AllTests COMMAND CSVTests)
