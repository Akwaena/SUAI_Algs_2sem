#include <stdio.h>

#define maxWord (64)
#define maxString (4096)

#define EOF (26) // Если у вас работает без этой строчки, то можно ее удалить

bool condition(char word[maxWord]);

int fourthLabTemplate () {
    char wordBuffer[maxWord]; // Сюда формируется слово
    char stringBuffer[maxString]; // А сюда строка

    short wordLength = 0;
    short stringLength = 0;

    char currentChar = getchar(); if (currentChar == EOF) {return 1;}
    char previousChar;

    while (currentChar != EOF) {
        if (currentChar == NULL) {return 1;}

        previousChar = currentChar;
        currentChar = getchar();

        if (currentChar == ' ' || currentChar == '.' || currentChar == ',' || currentChar == '\n') {
            if (condition(wordBuffer)) {
                for (short i; i < wordLength; ++i) {
                    stringBuffer[stringLength + i] = wordBuffer[i];
                }
                stringBuffer[stringLength + wordLength] = ',';
                stringBuffer[stringLength + wordLength + 1] = ' ';
                stringLength += wordLength + (short)2;
            }

            wordBuffer[0] = '\0';
            wordLength = 0;

        } else {
            wordBuffer[wordLength] = previousChar;
            wordLength++;
        }
    }

    printf("Resulting string: ");
    for (short i; i < stringLength; ++i) { printf("%c", stringBuffer[i]);}
}

bool condition(char word[maxWord]) {
    //Сюда вставьте условие своего варианта
    if (true) {
        return true;
    }
}
