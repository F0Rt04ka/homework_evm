cmake_minimum_required(VERSION 3.5)
project(lab2_consoleSC)

set(CMAKE_C_STANDARD 99)

set(SOURCE_EXE main.c)

set(SOURCE_LIB myTerms.c myTerms.h)

add_library(MyTerms STATIC ${SOURCE_LIB})

add_executable(lab2_consoleSC ${SOURCE_EXE})

target_link_libraries(lab2_consoleSC MyTerms)