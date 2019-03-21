cmake_minimum_required(VERSION 3.10)
project(study_c C)

set(CMAKE_C_STANDARD 99)

add_executable(study_c main.c)

add_executable(file file/file.c)
add_executable(cwd file/cwd.c)

add_subdirectory(libcurl)