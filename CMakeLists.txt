cmake_minimum_required(VERSION 3.7)

project(ORCsSBT VERSION 1.0.3.1 LANGUAGES CXX)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

add_subdirectory("src")
add_subdirectory("docs")
