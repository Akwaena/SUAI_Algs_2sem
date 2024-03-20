//
// Created by Akwaena on 08.02.2024.
// SUAI, Algorithms and Programming course, 2nd Semester
// 1st Lab work -- Linear Algorithms
// Task: Solve x^2+4x+3=0 quadratic equation
//
#include "libraries/akwaena.h"

int firstLab ()
{
    float A = 1;
    float B = 4;
    float C = 3;

    printf("Equation %.0fx^2+%.0fx+%.0f=0 has ", A, B, C);
    if (B*B - 4*A*C < 0) { printf("no real roots");}
    else if (B*B - 4*A*C == 0) { printf("one real root: %.2f", -B/(A*2));}
    else if (B*B - 4*A*C > 0) { printf("two real roots: %.2f and %.2f", (-B+sqrtf(B*B-4*A*C))/(A*2), (-B-sqrtf(B*B-4*A*C))/(A*2));}
    else { printf("чё");}
    return 0;
}


// tests
// None