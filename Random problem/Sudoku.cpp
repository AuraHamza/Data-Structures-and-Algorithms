#include<iostream>
using namespace std;
#define N 9
void printBoard(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int grid[N][N], int row ,int col, int num){
	for(int x=0;x<n;x++){
		if(grid[row][x]==num){
			return false;
		}
	}
	for(int x=0;x<n;x++){
		if(grid[x][col]==num){
			return false;
		}
	}
	int startrow=row-row%3;
	int startcol=col-col%3;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(grid[i+startrow][j+startcol]==num){
				return false;
			}
		}
	}
	return true;
}

bool solveSudoku(int grid[N][N],int row ,int col){
	if(row==N-1 && col==N){
		return true;
	}
	if(col==N){
		return solveSudoku(grid,row+1,0);
	}
	if(grid[row][col]!=0){
		return solveSudoku(grid,row,col+1);
	}
	for(int num=1 ;n<=9;num++){
		if(isSafe(grid,row,col,num)){
			grid[row][col]=num;
			
			if(isSafe(grid,row,col+1)){
				return true;
			}
		}
		grid[row][col]=0;
	}
	return false;
}
int main() {
    int grid[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if (solveSudoku(grid, 0, 0)) {
        printBoard(grid);
    } else {
        cout << "No solution exists";
    }

    return 0;
}
