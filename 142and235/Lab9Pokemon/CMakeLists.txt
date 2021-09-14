cmake_minimum_required(VERSION 3.19)
project(Lab9Pokemon)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab9Pokemon
        HashMapInterface.h
        main.cpp
        Pair.h
        SetInterface.h
        Set.h
        HashMap.h)
