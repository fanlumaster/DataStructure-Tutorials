cmake_minimum_required(VERSION 3.15)

project(dsdemo VERSION 1.0 LANGUAGES C CXX)

# include_directories(../src/include)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCES
    "src/ch03/3-3-stack.c"
)

set(MY_EXECUTABLE_NAME "build_dict")

add_executable(${MY_EXECUTABLE_NAME} ${SOURCES})