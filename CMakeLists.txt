cmake_minimum_required(VERSION 3.15)
project(pokemon)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(includes)

add_executable(pokemon src/main.cpp src/Pokemon.cpp src/Trainer.cpp includes/Trainer.h)