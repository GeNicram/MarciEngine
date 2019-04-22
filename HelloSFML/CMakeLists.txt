cmake_minimum_required(VERSION 3.7)

project(Marcinolaga)

# TODO: find package not working, because there is no sfml.cmake
# i have to use some workaround
#find_package(sfml REQUIRED COMPONENTS system window graphic)
find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML REQUIRED sfml-all)

add_executable(HelloSFML "main.cpp")

target_link_libraries(HelloSFML ${SFML_LIBRARIES})
target_include_directories(HelloSFML PUBLIC ${SFML_INCLUDE_DIRS})
target_compile_options(HelloSFML PUBLIC ${SFML_CFLAGS_OTHER})
