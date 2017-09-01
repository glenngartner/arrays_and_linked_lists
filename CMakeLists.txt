cmake_minimum_required( VERSION 3.8)

project (arrays-lists)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

include_directories ("${PROJECT_SOURCE_DIR}/include")

add_executable (linked_list ${SOURCES} include/linked_list_lib.hpp)