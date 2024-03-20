//
// Created by Akwaena on 14.02.2024.
// SUAI, Algorithms and Programming course, 2nd Semester
// 5th Lab work -- Linear arrays
// Task: Zero smaller half of 10 elements array.
//
// Testing runs:
// 1) input {"1 2 3 4 5 6 7 8 9 10"} >> output {"Modified Array: 0 0 0 0 0 6 7 8 9 10"}
// 2) input {"-2 -4 6 8 -10 12 14 -16 18 20"} >> output {"Modified Array: 0 0 0 0 0 12 14 -16 18 20"}

#include "libraries/akwaena.h"

int arraySize = 10;


int fifthLab() {
    int array[arraySize];

    printf("Enter %d integers for the array:\n", arraySize);
    for (int i = 0; i < arraySize; ++i) {
        if (scanf("%d", &array[i]) != 1) { printf("Error: Wrong value"); return 1;}
    }
    int sum_first_half = countInRange(array, arraySize, 0, arraySize/2);
    int sum_second_half = countInRange(array, arraySize, arraySize/2, arraySize);


    if (sum_first_half < sum_second_half) {
        modifyArray(array, arraySize, 0, arraySize/2, 0);
    } else if (sum_first_half >= sum_second_half) {
        modifyArray(array, arraySize, arraySize/2, arraySize, 0);
    }

    printf("Modified Array: ");
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}
