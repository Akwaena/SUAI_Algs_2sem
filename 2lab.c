//
// Created by Akwaena on 08.02.2024.
// SUAI, Algorithms and Programming course, 2nd Semester
// 2nd Lab work -- Cyclic Algorithms
// Task: Calculate the sum of the first elements of a series until absolute value of element exceeds epsilon
//
#include "libraries/akwaena.h"

int secondLab ()
{
    float returned = 0;
    int n = 1;
    float currentElement;
    float ε;


    printf("Enter epsilon value:");
    if (scanf("%f", &ε) != 1){ printf("Error: Wrong value for epsilon"); return 1;}

    currentElement = getSeriesElement_2(n);
    while (absf(currentElement) > ε)
    {
        returned += currentElement;

        n++;
        currentElement = getSeriesElement_2(n);
    }

    printf("Sum of series (epsilon = %f) is %.2f", ε, returned);
    return 0;
}

// test
// 1) input {0.1} >> output {"Sum of series (epsilon = 0.010000) is 1.19"}
// 2) input {1} >> output {"Sum of series (epsilon = 1.000000) is 0.00"}
// 3) input {0.15} >> output {"Sum of series (epsilon = 0.150000) is 0.82"}
