#include <stdio.h>

#define N 5 // Dimension of the maze

// Function prototypes
int solveMaze(int maze[N][N], int x, int y, int solution[N][N]);
void printSolution(int solution[N][N]);

// Check if (x, y) is a valid move
int isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0);
}

// Main function to solve the maze
int solveMaze(int maze[N][N], int x, int y, int solution[N][N]) {
    // If (x, y) is the bottom-right corner, the maze is solved
    if (x == N - 1 && y == N - 1) {
        solution[x][y] = 1;
        return 1;
    }

    // Check if maze[x][y] is a valid move
    if (isSafe(maze, x, y)) {
        // Mark x, y as part of the solution path
        solution[x][y] = 1;

        // Move right
        if (solveMaze(maze, x, y + 1, solution)) {
            return 1;
        }

        // Move down
        if (solveMaze(maze, x + 1, y, solution)) {
            return 1;
        }

        // Move left
        if (solveMaze(maze, x, y - 1, solution)) {
            return 1;
        }

        // Move up
        if (solveMaze(maze, x - 1, y, solution)) {
            return 1;
        }

        // Backtrack: unmark x, y as part of the solution path
        solution[x][y] = 0;
    }

    return 0;
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

    int solution[N][N] = {0};

    if (solveMaze(maze, 0, 0, solution)) {
        printf("Solution:\n");
        printSolution(solution);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
