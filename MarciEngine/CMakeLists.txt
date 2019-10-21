cmake_minimum_required(VERSION 3.7)

project(MarciEngine)

set(CMAKE_CXX_STANDARD 17)

#find_package(SFML REQUIRED system window graphic)
find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML REQUIRED sfml-all)

file(GLOB_RECURSE src *.cpp)

add_library (marciengine STATIC ${src})

target_link_libraries(marciengine ${SFML_LIBRARIES} pthread)
target_include_directories(marciengine PUBLIC ${SFML_INCLUDE_DIRS})
target_compile_options(marciengine PUBLIC ${SFML_CFLAGS_OTHER})
