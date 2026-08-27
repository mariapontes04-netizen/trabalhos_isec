cmake_minimum_required(VERSION 3.26)
project(Aula_6 C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_executable(Aula_6
        main.c
        tabela.c
        tabela.h
        ponto.c
        retangulo.c)
