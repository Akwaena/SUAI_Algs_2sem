//
// Created by Akwaena on 28.02.2024.
//

#ifndef SUAI_ALGS_2SEM_AKWAENA_H
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define SUAI_ALGS_2SEM_AKWAENA_H
#define EOF (26) //I DFK why this thing doesn't read EOF as -1, as intended, that just dumb

float sqrtf(float x);
float absf(float x);
float powf(float base, unsigned short power);
float getSeriesElement_2(int n);
int isPalindrome(const char *str);
int isPartOf(char targetChar, const char *str);
void strcpy(char destination[], const char source[]);
int strlen(const char *str);
int isStringInArray(const char *target, const char *array[], size_t arraySize);
int strcmp(const char *str1, const char *str2);
char* appendCharToString(char *originalString, char characterToAdd);
void modifyArray(int array[], size_t size, size_t lowerBound, size_t upperBound, int modifier);
int countInRange(int array[], size_t size, size_t lowerBound, size_t upperBound);
int countSetBits(unsigned char byte);

#endif //SUAI_ALGS_2SEM_AKWAENA_H
