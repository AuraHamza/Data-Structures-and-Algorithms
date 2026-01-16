#include <iostream>
using namespace std;
#define N 5   // Maze size (can change)

// Function to print solution path
void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

// Check if cell (x,y) is valid for rat
bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Recursive function to solve the maze
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    // If rat reaches destination (bottom-right)
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }
    // Check if maze[x][y] is valid
    if (isSafe(maze, x, y)) {
    	if (sol[x][y] == 1){
    		 return false;
		}
        // Mark current cell as part of solution path
        sol[x][y] = 1;
        // Move Down
        if (solveMazeUtil(maze, x , y+1, sol))
            return true;
        // Move Right
        if (solveMazeUtil(maze, x+1, y , sol))
            return true;
        // Move Up
        if (solveMazeUtil(maze, x , y-1, sol))
            return true;
        // Move Left
        if (solveMazeUtil(maze, x-1, y, sol))
            return true;
        // If none works ? Backtrack
        sol[x][y] = 0;
        return false;
    }
    return false;
}

// Main function to solve Rat in a Maze
bool solveMaze(int maze[N][N]) {
    int sol[N][N] = {0};  // Solution matrix initialized with 0

    if (!solveMazeUtil(maze, 0, 0, sol)) {
        cout << "No solution exists" << endl;
        return false;
    }

    cout << "Solution Path (1 means path taken):\n";
    printSolution(sol);
    return true;
}

// Driver code
int main() {
    int maze[N][N] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1}
    };

    solveMaze(maze);
    return 0;
}

