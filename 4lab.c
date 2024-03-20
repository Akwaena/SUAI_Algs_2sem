//
// Created by Akwaena on 12.02.2024.
// SUAI, Algorithms and Programming course, 2nd Semester
// 4th Lab work -- Character strings processing
// Task: Remove all repetitive words from input.
//
// Testing runs:
// 1) input {"hello world, world. This is a test. Test test test, hello.^Z\n"} >> output {"Resulting string is: "hello world This is a test Test"}
// 2) input {"The quick brown fox jumped over the lazy dog. Dog, dog! Fox fox fox. Lazy lazy lazy. Testing testing, one two three. Brown brown brown,\nquick quick quick.^Z\n"} >> output {"Resulting string is: "The quick brown fox jumped over the lazy dog Dog dog! Fox Lazy Testing testing one two three Brown"}
// 3) input {"A beautiful sunset painted the sky in hues of orange and pink. Pink clouds formed shapes that danced across the horizon.\nSunset, sky, and clouds. Orange orange orange. Testing, testing, 1 2 3.^Z\n"} >> output {"A beautiful sunset painted the sky in hues of orange and pink Pink clouds formed shapes that danced across horizon Sunset Orange Testing testing 1 2 3"}

#include "libraries/akwaena.h"

int fourthLab ()
{
    char** words = NULL;
    size_t wordCount = 0;


    printf("Enter stream (Ctrl+Z to end):\n");

    char *word = "";
    int inputSymbol;
    while ((inputSymbol = getchar()) != EOF) {
        if (!isPartOf(inputSymbol, " .,\n")) {
            char characterToAdd = (char) inputSymbol;
            word = appendCharToString(word, characterToAdd);
        } else {
            if (word != "") {
                if (!isStringInArray(word, words, wordCount)) {
                    words = (char **) realloc(words, (wordCount + 1) * sizeof(char *));
                    if (words == NULL) {
                        printf("Error: Failure to reallocate memory, while appending string to array\n");
                        exit(1);
                    }

                    words[wordCount] = word;
                    wordCount++;
                }
                word = "";
            }
        }
    }

    if (word != "") {
        if (!isStringInArray(word, words, wordCount)) {
            words = (char **) realloc(words, (wordCount + 1) * sizeof(char *));
            if (words == NULL) {
                printf("Error: Failure to reallocate memory, while appending string to array\n");
                return 1;
            }

            words[wordCount] = word;
            wordCount++;
        }
    }


    printf("Resulting string is:\n");
    for (size_t i = 0; i < wordCount; ++i) {
        printf("%s ", words[i]);
        free(words[i]);
    }

    getchar();

    free(word);
    return 0;
}


