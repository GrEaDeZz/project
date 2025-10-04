cmake_minimum_required(VERSION 3.16)
project(GitAndCMake C)

add_executable(GC main.c)

add_subdirectory(lib/SSDMMCStore)

target_link_libraries(GC kvstore)
