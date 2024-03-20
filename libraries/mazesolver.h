//
// Created by Akwaena on 28.02.2024.
//

#ifndef SUAI_ALGS_2SEM_MAZESOLVER_H
#include <stdio.h>
#include <string.h>
#define SUAI_ALGS_2SEM_MAZESOLVER_H
#define N (5)  // Number of rows
#define K (5)  // Number of columns

int isValid(int maze[N][K], int row, int col, int visited[N][K]);
void renderPath(int path[N][K], int maze[N][K], int _startRow, int _startCol, int _destinationRow, int _destinationCol);
int solveMazeUtil(int maze[N][K], int row, int col, int destinationRow, int destinationCol, int visited[N][K],
                  int path[N][K], int _startRow, int _startCol, int _destinationRow, int _destinationCol, int _maze[N][K]);
void solveMaze(int maze[N][K], int startRow, int startCol, int destinationRow, int destinationCol, int mazecpy[N][K]);

#endif //SUAI_ALGS_2SEM_MAZESOLVER_H
