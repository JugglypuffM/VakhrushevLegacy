cmake_minimum_required(VERSION 3.23)
project(CLion)

set(SOURCE_EXE main.cpp)

include_directories(foo home lessons)

add_executable(main ${SOURCE_EXE})

add_subdirectory(foo)
add_subdirectory(home)
add_subdirectory(lessons)

target_link_libraries(main foo home lessons)
