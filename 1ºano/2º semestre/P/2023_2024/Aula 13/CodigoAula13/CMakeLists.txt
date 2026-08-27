cmake_minimum_required(VERSION 3.26)
project(CodigoAula13 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(CodigoAula13
        banco.c
        banco.h
        ex2.c)
