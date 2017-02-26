cmake_minimum_required(VERSION 2.8)
project(homeworks_evm)

set(CMAKE_C_STANDARD 99)

set(SOURCE_EXE main.c)

set(SOURCE_LIB mySimpleComputer.c constantsRegisterFlags.h)

add_library(MySimpleComputer STATIC ${SOURCE_LIB})  #создание статической библиотеки

add_executable(homeworks_evm ${SOURCE_EXE})

target_link_libraries(homeworks_evm MySimpleComputer)
