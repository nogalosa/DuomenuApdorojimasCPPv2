cmake_minimum_required(VERSION 3.13)
project(DuomenuApdorojimasCPP)

set(CMAKE_CXX_STANDARD 11)

set(GCC_COVERAGE_COMPILE_FLAGS "-O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(DuomenuApdorojimas main.cpp main.h RandInt.cpp RandInt.h Studentas.h Asmuo.h)
add_executable(DuomenuApdorojimasArray main_array.cpp)