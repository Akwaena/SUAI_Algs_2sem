cmake_minimum_required(VERSION 3.27)
project(SUAI_Algs_2sem C)

set(CMAKE_C_STANDARD 23)

add_executable(SUAI_Algs_2sem
        libraries/akwaena.h
        libraries/akwaena.c
        libraries/interface.h
        libraries/interface.c
        libraries/labs.h
        libraries/mazesolver.c

        MainInterface.c
        1lab.c
        2lab.c
        3lab_v2.c
        4lab.c
        5lab.c
        6lab.c
        7lab.c
        4labTemplate.c)
