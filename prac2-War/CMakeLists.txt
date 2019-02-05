cmake_minimum_required(VERSION 2.8)
project(war CXX)
set(CMAKE_CXX_FLAGS -std=c++14)
add_executable(War main.cpp card.cpp player.cpp)