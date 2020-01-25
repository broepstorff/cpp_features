cmake_minimum_required(VERSION 3.16.3)

project(cpp_features)

file(GLOB SOURCES "src/*.cpp")

add_executable(cpp_features ${SOURCES})