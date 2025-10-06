cmake_minimum_required(VERSION 3.21)

project(GitAndCMake C)

add_executable(GC main.c)

target_include_directories(GC PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)

add_subdirectory(lib/SSDMMCStore)

target_link_libraries(GC kvstore)

target_compile_options(GC PRIVATE -O3 -Wall -Wextra -Werror)