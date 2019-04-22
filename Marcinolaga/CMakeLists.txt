cmake_minimum_required(VERSION 3.7)

project(Marcinolaga)

set(CMAKE_CXX_STANDARD 11)

include_directories("../MarciEngine/")

file(GLOB_RECURSE src *.cpp)

add_executable(Marcinolaga ${src})

target_link_libraries(Marcinolaga marciengine)
