cmake_minimum_required(VERSION 3.17)
project(Lab7_3DMaze)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab7_3DMaze main.cpp MazeInterface.h Maze.h input.txt output.txt)