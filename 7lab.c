//
// Created by Akwaena on 28.02.2024.
// SUAI, Algorithms and Programming course, 2nd Semester
// 7rd Lab work -- Bitwise processing of integers
// Task: Count the number of 1 in each byte of number N.
//
// Testing runs:
// 1) input {255} >> output {8 0 0 0}
// 2) input {65535} >> output {8 8 0 0}
// 3) input {2147483647} >> output {8 8 8 8}

#include "libraries/akwaena.h"

int seventhLab () {
    unsigned int N;
    printf("Enter a number: ");
    if (scanf("%u", &N) != 1) { printf("Error: wrong number"); return 1;};

    unsigned char *bytes = (unsigned char*)&N;
    printf("Number N=%u has the corresponding number of 1s in each byte:\n", N);
    for (short i = 0; i < sizeof N; ++i) {
        printf("%hd byte: %d\n", i+1, countSetBits(bytes[i]));
    }
    return 0;
}
