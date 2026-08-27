cmake_minimum_required(VERSION 3.26)
project(Aula_5 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Aula_5
        main.c
        ponto.c
        ponto.h
        retangulo.c
        retangulo.h)
