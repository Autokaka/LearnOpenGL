cmake_minimum_required(VERSION 3.20.0)

project(glad)

file(GLOB_RECURSE SOURCES src/*)
source_group(TREE ${PROJECT_SOURCE_DIR})

add_library(glad STATIC ${SOURCES})
target_include_directories(glad PUBLIC include)
