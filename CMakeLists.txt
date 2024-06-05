cmake_minimum_required(VERSION 3.27)
project(AiZO2)

set(CMAKE_CXX_STANDARD 17)

add_executable(AiZO2 main.cpp
        Helpers/Generator.cpp
        Helpers/Generator.h)
