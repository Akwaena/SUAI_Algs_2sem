//
// Created by Akwaena on 14.02.2024.
//

#include "Libraries/mazesolver.h"


int _maze[N][K] = {
        {0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
};

int _startRow = 0, _startCol = 0;
int _destinationRow = 4, _destinationCol = 0;

int sixthLab() {
    int maze[N][K];
    memcpy(maze, _maze, sizeof(_maze));

    printf("Maze Solution:\n");
    solveMaze(maze, _startRow, _startCol, _destinationRow, _destinationCol, _maze);

    getchar();
    return 0;
}
