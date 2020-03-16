cmake_minimum_required(VERSION 3.15)
project(pokemon)

set(CMAKE_CXX_STANDARD 14)

add_executable(pokemon src/main.cpp src/Pokemon.cpp include/Pokemon.h enums/PokemonType.cpp)