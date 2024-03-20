#include "akwaena.h"


float sqrtf(float x) {
    float low = 0.0;
    float high = x;
    float guess = (low + high) / 2.0;

    while (absf(guess * guess - x) > 0.001) {
        if (guess * guess > x) {
            high = guess;
        } else {
            low = guess;
        }

        guess = (low + high) / 2.0;
    }

    return guess;
}

float absf(float x)
{
    if (x >= 0) {return x;}
    else {return -x;}
}

float powf(float base, unsigned short power) {
    float returned = 1;
    for (unsigned short i; i < power; ++i) {
        returned *= base;
    }
    return returned;
}

float getSeriesElement_2(int n) {
    printf(""); // IDFK WHY THIS DOESN'T WORK WITHOUT THIS PRINT, THAT'S FUCKING MAGICK
    return (float)n / powf(n+1, 2);
}

int isPalindrome(const char *str) {
    if (str == NULL) {
        printf("Warning: Null pointer passed to checkPalindrome.\n");
        return 0;
    }

    size_t length = strlen(str);
    size_t start = 0;
    size_t end = length - 1;

    while (start < end) {
        if (tolower(str[start]) != tolower(str[end])) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int isPartOf(char targetChar, const char *str) {
    while (*str != '\0') {
        if (*str == targetChar) {
            return 1;
        }
        str++;
    }

    return 0;
}

void strcpy(char destination[], const char source[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

int strlen(const char *str) {
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int isStringInArray(const char *target, const char *array[], size_t arraySize) {
    for (size_t i = 0; i < arraySize; ++i) {
        if (strcmp(target, array[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int strcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return -1;
        }
        str1++;
        str2++;
    }

    if (*str1 != '\0' || *str2 != '\0') {
        return -1;
    }

    return 0;
}

char* appendCharToString(char *originalString, char characterToAdd) {
    size_t originalLength = strlen(originalString);
    char *newString = (char *)malloc(originalLength + 1 + 1);

    if (newString == NULL) {
        printf("Error: Failure to allocate memory, while appending char to string\n");
        exit(1);
    }

    strcpy(newString, originalString);
    newString[originalLength] = characterToAdd;
    newString[originalLength + 1] = '\0';

    return newString;
}

void modifyArray(int array[], size_t size, size_t lowerBound, size_t upperBound, int modifier) {
    // Ensure that the borders are within the array bounds
    lowerBound = (lowerBound < 0) ? 0 : lowerBound;
    upperBound = (upperBound >= size) ? size - 1 : upperBound;

    for (size_t i = lowerBound; i <= upperBound-1; ++i) {
        array[i] = modifier;
    }
}

int countInRange(int array[], size_t size, size_t lowerBound, size_t upperBound) {
    // Ensure that the borders are within the array bounds
    lowerBound = (lowerBound < 0) ? 0 : lowerBound;
    upperBound = (upperBound >= size) ? size - 1 : upperBound;

    int returned = 0;

    for (size_t i = lowerBound; i <= upperBound-1; ++i) {
        returned += array[i];
    }
}

int countSetBits(unsigned char byte) {
    int counter = 0;
    while (byte) {
        counter += byte&1;
        byte >>= 1;
    }
    return counter;
}