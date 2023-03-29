cmake_minimum_required(VERSION 3.23)

project(home)

set(SOURCE_LIB addition.cpp Vector.cpp)

add_library(home STATIC ${SOURCE_LIB})