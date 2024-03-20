#include "libraries/interface.h"
#include "libraries/labs.h"
#include "libraries/akwaena.h"


int main () {
    system("cls");
    while (true) {
        printBoldBorder();
        printAtCenter("SUAI Algorithms -- labs");
        printThinBorder();
        printAtCenter("Made by Akwaena");
        printAtCenter("2024");
        printBoldBorder();
        printAtCenter("There's 7ish labs to run:");
        printAtCenter("");
        printAtLeft("1. Linear algorithms");
        printAtLeft("2. Cyclic algorithms");
        printAtLeft("3. Character stream processing");
        printAtLeft("4. Character strings processing");
        printAtLeft("-4. 4th lab template");
        printAtLeft("5. Linear arrays");
        printAtLeft("6. 2D arrays");
        printAtLeft("7. Bitwise processing of integer");
        printThinBorder();
        printAtCenter("Choose lab by typing in corresponding number (-1 to exit):");
        int labToRun;
        input(&labToRun);

        switch (labToRun) {
            case -1:
                printAtCenter("Exiting program...");
                printBoldBorder();
                return 0;
            case 1:
                printAtCenter("Starting first lab...");
                printExitBorder();
                printf("\nLab ended with exit code %d", firstLab()); getchar(); getchar();
                break;
            case 2:
                printAtCenter("Starting second lab...");
                printExitBorder();
                printf("\nLab ended with exit code %d", secondLab()); getchar(); getchar();
                break;
            case 3:
                printAtCenter("Starting third lab...");
                printExitBorder();
                printf("\nLab ended with exit code %d", thirdLab()); getchar(); getchar();
                break;
            case 4:
                printAtCenter("Starting fourth lab...");
                printExitBorder();
                printf("\nLab ended with exit code %d", fourthLab()); getchar(); getchar();
                break;
            case -4:
                printAtCenter("Starting fourth lab template...");
                printExitBorder();
                printf("\nLab ended with exit code %d", fourthLabTemplate()); getchar(); getchar();
                break;
            case 5:
                printAtCenter("Starting fifth lab...");
                printExitBorder();
                printf("\nLab ended with exit code %d", fifthLab()); getchar(); getchar();
                break;
            case 6:
                printAtCenter("Starting sixth lab...");
                printExitBorder();
                printf("\nLab ended with exit code %d", sixthLab()); getchar(); getchar();
                break;
            case 7:
                printAtCenter("Starting seventh lab...");
                printExitBorder();
                printf("\nLab ended with exit code %d", seventhLab()); getchar(); getchar();
                break;
            default:
                printAtCenter("There's no such lab!");
                printBoldBorder();getchar(); getchar();
                break;
        }
        printExitBorder();
        system("cls");
    }
}