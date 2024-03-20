//
// Created by Akwaena on 09.02.2024.
// SUAI, Algorithms and Programming course, 2nd Semester
// 3rd Lab work -- Character stream processing
// Task: Count the number of palindrome words in a stream of symbols.
//
// Testing runs:
// 1) input {"lool^Z\n"} >> output {"There's 1 palindrome"}
// 2) input {"lool.boob rawr,geptil\nwow^Z\n"} >> output {"There're 3 palindromes"}
// 3) input {"a^Z\n"} >> output {"There's 1 palindrome"}
#include "libraries/akwaena.h"

int thirdLab ()
{
    int counter = 0;

    printf("Enter stream (Ctrl+Z to end):\n");

    char *word = "";
    int inputSymbol;
    while ((inputSymbol = getchar()) != EOF) {
        if (!isPartOf(inputSymbol, " .,\n")) {
            char characterToAdd = (char) inputSymbol;
            word = appendCharToString(word, characterToAdd);
        }
        else {
            counter += isPalindrome(word);
            word = "";
        }
    }

    if (word != "") // This catches case when last word isn't delimited from EOF
    {
        counter += isPalindrome(word);
        word = "";
    }


    if (counter != 1) { printf("There're %d palindromes", counter);}
    else { printf("There's 1 palindrome");}
    getchar();

    free(word);
    return 0;
}
