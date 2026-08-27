cmake_minimum_required(VERSION 3.26)
project(Aula9 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Aula9
        main.c
        parque.c
        parque.h)
