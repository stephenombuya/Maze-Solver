#include <stdio.h>
#include <stdbool.h>

#define N 5 // Dimension of the maze

// Function prototypes
bool solveMaze(int maze[N][N], int x, int y, int solution[N][N]);
void printSolution(int solution[N][N]);
void initializeSolution(int solution[N][N]);

// Check if (x, y) is a valid move
bool isSafe(int maze[N][N], int x, int y, int solution[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0 && solution[x][y] == 0);
}

// Function to initialize the solution matrix
void initializeSolution(int solution[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            solution[i][j] = 0;
        }
    }
}

// Main function to solve the maze
bool solveMaze(int maze[N][N], int x, int y, int solution[N][N]) {
    // If (x, y) is the bottom-right corner, the maze is solved
    if (x == N - 1 && y == N - 1 && maze[x][y] == 0) {
        solution[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is a valid move
    if (isSafe(maze, x, y, solution)) {
        // Mark x, y as part of the solution path
        solution[x][y] = 1;

        // Move right
        if (solveMaze(maze, x, y + 1, solution)) {
            return true;
        }

        // Move down
        if (solveMaze(maze, x + 1, y, solution)) {
            return true;
        }

        // Move left
        if (solveMaze(maze, x, y - 1, solution)) {
            return true;
        }

        // Move up
        if (solveMaze(maze, x - 1, y, solution)) {
            return true;
        }

        // Backtrack: unmark x, y as part of the solution path
        solution[x][y] = 0;
    }

    return false;
}

// Function to print the solution
void printSolution(int solution[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", solution[i][j]);
        }
        printf("\n");
    }
}

// Driver program
int main() {
    int maze[N][N] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };

    int solution[N][N];
    initializeSolution(solution);

    if (solveMaze(maze, 0, 0, solution)) {
        printf("Solution:\n");
        printSolution(solution);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
