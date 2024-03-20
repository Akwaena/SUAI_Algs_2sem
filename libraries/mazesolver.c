#include "mazesolver.h"

int isValid(int maze[N][K], int row, int col, int visited[N][K]) {
    return (row >= 0 && row < N && col >= 0 && col < K && maze[row][col] == 0 && !visited[row][col]);
}

void renderPath(int path[N][K], int maze[N][K], int _startRow, int _startCol, int _destinationRow, int _destinationCol) {
    for (int j = 0; j < K; j++) {
        printf("+---");
    }
    printf("+\n");


    for (int i = 0; i < N; i++) {
        printf("|");
        for (int j = 0; j < K; j++) {
            if (i == _startRow && j == _startCol) {
                // Entrance
                printf(" > ");
            } else if (i == _destinationRow && j == _destinationCol) {
                // Exit
                printf(" @ ");
            } else if (maze[i][j] == 1) {
                // Wall rendering
                printf(" # ");
            } else if (path[i][j] == 1) {
                // Path rendering
                printf(" o ");
            } else {
                // Blank space
                printf("   ");
            }
            printf("|");
        }
        printf("\n");

        for (int j = 0; j < K; j++) {
            printf("+---");
        }
        printf("+\n");
    }
}

int solveMazeUtil(int maze[N][K], int row, int col, int destinationRow, int destinationCol, int visited[N][K],
                  int path[N][K], int _startRow, int _startCol, int _destinationRow, int _destinationCol, int _maze[N][K]) {
    if (row == destinationRow && col == destinationCol) {
        path[row][col] = 1;
        renderPath(path, _maze, _startRow, _startCol, _destinationRow, _destinationCol);
        return 1;  // Reached the destination
    }

    // Mark the current cell as visited
    visited[row][col] = 1;

    // Try moving in all 4 directions: up, down, left, right
    if (isValid(maze, row - 1, col, visited)) {  // Up
        path[row][col] = 1;
        if (solveMazeUtil(maze, row - 1, col, destinationRow, destinationCol, visited, path,
                          _startRow, _startCol, _destinationRow, _destinationCol, _maze))
            return 1;
        path[row][col] = 0;  // Backtrack
    }

    if (isValid(maze, row + 1, col, visited)) {  // Down
        path[row][col] = 1;
        if (solveMazeUtil(maze, row + 1, col, destinationRow, destinationCol, visited, path,
                          _startRow, _startCol, _destinationRow, _destinationCol, _maze))
            return 1;
        path[row][col] = 0;  // Backtrack
    }

    if (isValid(maze, row, col - 1, visited)) {  // Left
        path[row][col] = 1;
        if (solveMazeUtil(maze, row, col - 1, destinationRow, destinationCol, visited, path,
                          _startRow, _startCol, _destinationRow, _destinationCol, _maze))
            return 1;
        path[row][col] = 0;  // Backtrack
    }

    if (isValid(maze, row, col + 1, visited)) {  // Right
        path[row][col] = 1;
        if (solveMazeUtil(maze, row, col + 1, destinationRow, destinationCol, visited, path,
                          _startRow, _startCol, _destinationRow, _destinationCol, _maze))
            return 1;
        path[row][col] = 0;  // Backtrack
    }

    // If none of the directions work, mark the current cell as not part of the solution
    visited[row][col] = 0;
    return 0;
}

void solveMaze(int maze[N][K], int startRow, int startCol, int destinationRow, int destinationCol, int mazecpy[N][K]) {
    int visited[N][K] = {0};  // Initialize all cells as not visited
    int path[N][K] = {0};     // Initialize the path array

    if (!solveMazeUtil(maze, startRow, startCol, destinationRow, destinationCol, visited, path,
                       startRow, startCol, destinationRow, destinationCol, mazecpy)) {
        printf("No path found.\n");
    }
}

