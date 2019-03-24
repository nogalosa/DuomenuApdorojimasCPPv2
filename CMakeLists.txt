cmake_minimum_required(VERSION 3.13)
project(DuomenuApdorojimasCPP)

set(CMAKE_CXX_STANDARD 11)

add_executable(DuomenuApdorojimas main.cpp main.h RandInt.cpp RandInt.h)
add_executable(DuomenuApdorojimasArray main_array.cpp)