cmake_minimum_required(VERSION 3.15...3.31)

project(Project-Zeta VERSION 0.1 DESCRIPTION "A Coding Language Made In C++" LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)

if(APPLE)
    set(CMAKE_OSX_ARCHITECTURES arm64;x86_64)

endif(APPLE)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(zeta src/main.c)

add_executable(zetac src/compile/compile.cpp src/compile/lexer.cpp)


target_include_directories(zeta PUBLIC include)

target_include_directories(zetac PUBLIC include)