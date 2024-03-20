//
// Created by Akwaena on 08.02.2024.
// SUAI, Algorithms and Programming course, 2nd Semester
// 1st Lab work -- Linear Algorithms
//

#include "stdio.h"
#include "math.h"

int main ()
{
    // variables
    float returned;
    float v1, t, v2;

    // input
    printf("Enter value of A:");
    if (scanf("%f", &v1) != 1)
    {
        printf("Error: invalid input for A number");
        return -1;
    }

    printf("Enter value of B:");
    if (scanf("%f", &t) != 1)
    {
        printf("Error: invalid input for B number");
        return -1;
    }

    printf("Enter value of C:");
    if (scanf("%f", &v2) != 1)
    {
        printf("Error: invalid input for C number");
        return -1;
    }

    //processing and output
    float a = (v1-v2)/t;
    returned = v1*t + (a* pow(t, 2))/2;
    printf("\nResult: %.2f", returned);
    return 0;
}
