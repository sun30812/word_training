cmake_minimum_required(VERSION 3.19)
project(word_training)

set(CMAKE_CXX_STANDARD 20)

add_executable(word_training main.cpp dictionary.h dictionary.cpp)