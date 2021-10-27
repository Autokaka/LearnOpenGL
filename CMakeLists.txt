cmake_minimum_required(VERSION 3.20.0)

project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(third-party)

file(GLOB_RECURSE SOURCES src/*)
add_executable(LearnOpenGL ${SOURCES})

target_link_libraries(LearnOpenGL PUBLIC glad SDL2)
