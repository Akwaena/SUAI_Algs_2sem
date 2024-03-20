#include "interface.h"

void printAtCenter(char *toPrint) {
    printSideBorder();
    if (strlen(toPrint) <= interfaceWidth) {
        for (size_t i=0; i<=(interfaceWidth-strlen(toPrint))/2; ++i) { printf(" ");}
        printf("%s", toPrint);
        if ((interfaceWidth-strlen(toPrint))%2 == 0) {
            for (size_t i=0; i<=(interfaceWidth-strlen(toPrint))/2-1; ++i) { printf(" ");}
        }
        else {for (size_t i=0; i<=(interfaceWidth-strlen(toPrint))/2; ++i) { printf(" ");}}
    }
    else { printf("Interface overflow"); exit(1);}
    printSideBorder(); printf("\n");
}

void printAtLeft(char *toPrint) {
    printSideBorder();
    if (strlen(toPrint) <= interfaceWidth) {
        for (size_t i=0; i<=interfaceWidth/4; ++i) { printf(" ");}
        printf("%s", toPrint);
        for (size_t i=0; i<=interfaceWidth - interfaceWidth/4 - strlen(toPrint) - 1; ++i) { printf(" ");}
    }
    else { printf("Interface overflow"); exit(1);}
    printSideBorder(); printf("\n");
}

void printBoldBorder() {for (short i = 0; i <= interfaceWidth+sideBorderWidth*2; ++i) {printf("=");} printf("\n");}
void printExitBorder() {for (short i = 0; i <= interfaceWidth+sideBorderWidth*2; ++i) {printf("V");} printf("\n");}
void printThinBorder() {
    printSideBorder();
    for (short i = 0; i <= interfaceWidth; ++i) {printf("_");}
    printSideBorder(); printf("\n");}
void printSideBorder() { for (short i = 0; i < sideBorderWidth; ++i) { printf("|");}}

void input(int *target) {
    printExitBorder();
    printf(">> ");
    while (scanf("%d", target) != 1) { printf("\b"); printf("<<Wrong number, try again\n");
        getchar();
        printf(">> ");}
    printf("\b");
    printExitBorder();
}