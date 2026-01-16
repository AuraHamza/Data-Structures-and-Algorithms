#include <iostream>
using namespace std;
#define N 5

bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    // Base case: destination reached
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        // If already visited, avoid loops
        if (sol[x][y] == 1)
            return false;

        // Mark current cell as part of solution path
        sol[x][y] = 1;

        // Move down
        if (solveMazeUtil(maze, x + 1, y, sol))
            return true;

        // Move right
        if (solveMazeUtil(maze, x, y + 1, sol))
            return true;

        // Move up
        if (solveMazeUtil(maze, x - 1, y, sol))
            return true;

        // Move left
        if (solveMazeUtil(maze, x, y - 1, sol))
            return true;

        // Backtrack
        sol[x][y] = 0;
        return false;
    }
    return false;
}

void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

bool solveMaze(int maze[N][N]) {
    int sol[N][N] = {0};

    if (!solveMazeUtil(maze, 0, 0, sol)) {
        cout << "No solution found!" << endl;
        return false;
    }

    cout << "Solution Path:\n";
    printSolution(sol);
    return true;
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1},
    };

    solveMaze(maze);
    return 0;
}

