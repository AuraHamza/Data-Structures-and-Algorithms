#include <iostream>
using namespace std;
#define N 4

bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check the same column above
    for (i = 0; i < row; i++) {
        if (board[i][col])//True when queen is present  
            return false;
    }

    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])//True when queen is present  
            return false;
    }

    // Check upper right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j])//True when queen is present  
            return false;
    }

    return true;
}

bool solveNqueen(int board[N][N], int row) {
    // Base case: all queens placed
    if (row >= N)
        return true;

    for (int i = 0; i< N; i++) {
        if (isSafe(board, row, i)) {
            board[row][i] = 1;

            // Recur for next row
            if (solveNqueen(board, row + 1))
                return true;

            // Backtrack
            board[row][i] = 0;
        }
    }

    return false;
}

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool solve() {
    int board[N][N] = {0};

    if (!solveNqueen(board, 0)) {
        cout << "Solution does not exist\n";
        return false;
    }

    printSolution(board);
    return true;
}

int main() {
    solve();
    return 0;
}

