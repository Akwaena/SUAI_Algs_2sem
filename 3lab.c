//
// Created by Akwaena on 09.02.2024.
// SUAI, Algorithms and Programming course, 2nd Semester
// 3rd Lab work -- Character stream processing
// Task: Count the number of palindrome words in a stream of symbols.
//
// Known issue: program doesn't end if EOF char is typed not after empty string,
// but while stdin is replaced by txt everything works just fine, so just live with it ¯\_(ツ)_/¯

#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"

#define EOF (26) //I DFK why this thing doesn't read EOF as -1, as intended, that just dumb

int checkPalindrome(char *str);
int countPalindromes(char *stream);
void convertToLower(char *str);
int strlen(const char *str);
void strrev(char str[]);
int strcmp(const char *str1, const char *str2);
void strcpy(char destination[], const char source[]);

int main ()
{
    int len;
    printf("Specify max stream length:");
    if (scanf("%d", &len) != 1) { printf("Error: Wrong length value"); return -1;}
    char stream[len];
    int counter = 0;

    printf("Write the stream, followed by ^D at the very end:");
    getchar();


    // Taking input by strings and processing them one by one until last empty string
    while (fgets(stream, len, stdin) != NULL) {
        // Clearing stream from trash, so boob^Z would still be palindrome
        int i, j = 0;
        for (i = 0; i < strlen(stream); i++) {
            if (stream[i] != '\0' && stream[i] != EOF) {
                stream[j++] = stream[i];
            }
        }
        stream[j] = '\0';

        // Adding count of palindromes from string to total value
        counter += countPalindromes(stream);
    }

    if (counter != 1) {printf("There're %d palindromes", counter);}
    else { printf("There's 1 palindrome");}
    getchar();
    return 0;
}

int checkPalindrome (char *str)
{
    if (str == NULL || strlen(str) < 2) {
        printf("Warning: Null pointer/too short word passed to checkPalindrome.\n");
        return 0;
    }

    convertToLower(str);
    char reversed[strlen(str)];
    strcpy(reversed, str);
    strrev(reversed);
    return strcmp(reversed, str) + 1;
}

int countPalindromes (char *stream) {
    int count = 0;

    char delimiters[] = " .,\n";
    char *token = strtok(stream, delimiters);

    while (token != NULL) {
        if (checkPalindrome(token) == 1) {count++;}
        token = strtok(NULL, delimiters);
    }

    return count;
}

void convertToLower(char *str)
{
    while (*str)
    {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

// test
// 1) input {"lool^Z\n"} >> output {"There's 1 palindrome"}
// 2) input {"lool.boob rawr,geptil\nwow^Z\n"} >> output {"There're 3 palindromes"}
// 3) input {"a^Z\n"} >> output {"Warning: Null pointer/too short word passed to checkPalindrome\nThere're 0 palindromes"}





int strlen(const char *str) {
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    }

    return length;
}

void strrev(char str[]) {
    int length = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
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

void strcpy(char destination[], const char source[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

char** tokenizeString(const char* inputString, const char* delimiters, int* tokenCount) {
    // Check for NULL input
    if (inputString == NULL || delimiters == NULL || tokenCount == NULL) {
        return NULL;
    }

    // Count the number of tokens
    *tokenCount = 1;  // At least one token
    for (const char* c = inputString; *c != '\0'; ++c) {
        if (strchr(delimiters, *c) != NULL) {
            (*tokenCount)++;
        }
    }

    // Allocate memory for an array of strings
    char** tokens = (char**)malloc(*tokenCount * sizeof(char*));
    if (tokens == NULL) {
        return NULL;  // Memory allocation failed
    }

    // Copy tokens into the array
    char* token = strtok((char*)inputString, delimiters);
    int i = 0;
    while (token != NULL) {
        tokens[i] = strdup(token);
        if (tokens[i] == NULL) {
            // Memory allocation failed, free previously allocated memory and return NULL
            for (int j = 0; j < i; ++j) {
                free(tokens[j]);
            }
            free(tokens);
            return NULL;
        }
        token = strtok(NULL, delimiters);
        i++;
    }

    return tokens;
}
