# cmake_minimum_required(VERSION <specify CMake version here>)
project(homework_evm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES_LIB_LAB1
        lab1_mySimpleComputer/mySimpleComputer.c
        lab1_mySimpleComputer/mySimpleComputer.h)
set(SOURCE_FILES_LIB_LAB2
        lab2_consoleSC/myTerms.c
        lab2_consoleSC/myTerms.h)
set(SOURCE_FILES_LIB_LAB3
        lab3_myBigChars/bc_bigcharread.c
        lab3_myBigChars/bc_bigcharwrite.c
        lab3_myBigChars/bc_box.c
        lab3_myBigChars/bc_getbigcharpos.c
        lab3_myBigChars/bc_printA.c
        lab3_myBigChars/bc_printbigchar.c
        lab3_myBigChars/bc_setbigcharpos.c
        lab3_myBigChars/myBigChars.h)

add_executable(homework_evm ${SOURCE_FILES})