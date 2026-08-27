cmake_minimum_required(VERSION 3.26)
project(Aula_7 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Aula_7
        agenda.c
        agenda.h
        main.c)
