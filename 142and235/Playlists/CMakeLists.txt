cmake_minimum_required(VERSION 3.17)
project(Playlists)

set(CMAKE_CXX_STANDARD 14)

add_executable(Playlists main.cpp Song.cpp Song.h Playlist.cpp Playlist.h)