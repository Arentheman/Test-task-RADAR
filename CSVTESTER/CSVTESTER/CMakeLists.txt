cmake_minimum_required(VERSION 3.10)
project(CSVTESTER)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(LIB_SOURCES
    CSVTable.cpp
    FormulaEvaluator.cpp
)

add_library(CSVReaderLib STATIC ${LIB_SOURCES})
target_include_directories(CSVReaderLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(CSVTESTER main.cpp)
target_link_libraries(CSVTESTER CSVReaderLib)
