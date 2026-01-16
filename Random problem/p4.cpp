#include<iostream>
using namespace std;
#define N 4

bool isSafe(int board[N][N],int row,int column){
	int i,j;
	
	for(i=0;i<row;i++){
		if(board[i][col]){
			return false;
		}
	}
	for(i=row,j=col ; i>=0 && j>=0 ; i-- ,j--){
		if(board[i][j]){
			return false;
		}
	}
	for(i=row ,j=col;i>=0 && j<N ;i-- ,j++){
		if(board[i][j]){
			return false;
		}
	}
	return true;
}

bool SolveNqueen(int board[N][N],int row){
	if(row>=N){
		return true;
		for(int i=0;i<n;i++){
			if(isSafe(board,row,i)){
				board[row][i]=1;
			}
			
			if(SolveNqueen(board,row+1)){
				return true;
			}
			
			board[row][i]=0;
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

bool solve(){
	int board[N][N]={0};
	if(!SolveNqueen(board,0)){
		 cout << "Solution does not exist\n";
        return false;
	}
	printSolution(int board[N][N]);
	return true;
}
int main(){
	solve();
	return 0;
}
