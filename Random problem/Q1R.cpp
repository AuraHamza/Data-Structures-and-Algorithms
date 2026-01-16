#include <iostream>
using namespace std;

bool areSame(char **A, char **B, int n) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (A[r][c] != B[r][c])
                return false;
        }
    }
    return true;
}

void shiftUp(char **grid, int n) {
    for (int col = 0; col < n; ++col) {
        for (int row = 1; row < n; ++row) {
            if (grid[row][col] != '.') {
                int k = row;
                while (k > 0 && grid[k - 1][col] == '.') {
                    char temp = grid[k - 1][col];
                    grid[k - 1][col] = grid[k][col];
                    grid[k][col] = temp;
                    k--;
                }
            }
        }
    }
}

void shiftDown(char **grid, int n) {
    for (int col = 0; col < n; ++col) {
        for (int row = n - 2; row >= 0; --row) {
            if (grid[row][col] != '.') {
                int k = row;
                while (k < n - 1 && grid[k + 1][col] == '.') {
                    char t = grid[k + 1][col];
                    grid[k + 1][col] = grid[k][col];
                    grid[k][col] = t;
                    k++;
                }
            }
        }
    }
}

void shiftLeft(char **grid, int n) {
    for (int row = 0; row < n; ++row) {
        for (int col = 1; col < n; ++col) {
            if (grid[row][col] != '.') {
                int k = col;
                while (k > 0 && grid[row][k - 1] == '.') {
                    char temp = grid[row][k - 1];
                    grid[row][k - 1] = grid[row][k];
                    grid[row][k] = temp;
                    k--;
                }
            }
        }
    }
}

void shiftRight(char **grid, int n) {
    for (int row = 0; row < n; ++row) {
        for (int col = n - 2; col >= 0; --col) {
            if (grid[row][col] != '.') {
                int k = col;
                while (k < n - 1 && grid[row][k + 1] == '.') {
                    char temp = grid[row][k + 1];
                    grid[row][k + 1] = grid[row][k];
                    grid[row][k] = temp;
                    k++;
                }
            }
        }
    }
}

void performMove(char **grid, int n, int dir) {
    if (dir == 0) shiftLeft(grid, n);
    else if (dir == 1) shiftDown(grid, n);
    else if (dir == 2) shiftRight(grid, n);
    else if (dir == 3) shiftUp(grid, n);
}

bool attemptSolve(char **goal, char **state, int n, int used[4]) {
    if (areSame(goal, state, n))
        return true;

    for (int i = 0; i < 4; ++i) {
        if (used[i]) continue;
        used[i] = 1;

        char **temp = new char*[n];
        for (int r = 0; r < n; ++r) {
            temp[r] = new char[n];
            for (int c = 0; c < n; ++c)
                temp[r][c] = state[r][c];
        }

        performMove(temp, n, i);

        bool result = attemptSolve(goal, temp, n, used);

        for (int r = 0; r < n; ++r) delete[] temp[r];
        delete[] temp;

        used[i] = 0;
        if (result) return true;
    }
    return false;
}

int main() {
    int n;
    cout << "Enter size of square grid: ";
    cin >> n;

    char **start = new char*[n];
    char **target = new char*[n];
    char **copyGrid = new char*[n];

    for (int i = 0; i < n; ++i) {
        start[i] = new char[n];
        target[i] = new char[n];
        copyGrid[i] = new char[n];
    }

    cout << "Enter initial grid:\n";
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < n; ++c)
            cin >> start[r][c];

    cout << "Enter goal grid:\n";
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < n; ++c)
            cin >> target[r][c];

    for (int r = 0; r < n; ++r)
        for (int c = 0; c < n; ++c)
            copyGrid[r][c] = start[r][c];

    int usedDirs[4] = {0, 0, 0, 0};

    bool canTransform = attemptSolve(target, copyGrid, n, usedDirs);

    cout << (canTransform ? "yes" : "no") << endl;

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c)
            cout << copyGrid[r][c] << ' ';
        cout << '\n';
    }

    for (int i = 0; i < n; ++i) {
        delete[] start[i];
        delete[] target[i];
        delete[] copyGrid[i];
    }
    delete[] start;
    delete[] target;
    delete[] copyGrid;

    return 0;
}