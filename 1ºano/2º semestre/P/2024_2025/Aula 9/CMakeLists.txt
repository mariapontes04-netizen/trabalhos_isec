cmake_minimum_required(VERSION 3.26)
project(Aula_9 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Aula_9
        main.c
        parque.c
        parque.h)
