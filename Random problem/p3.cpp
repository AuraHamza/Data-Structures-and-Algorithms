#include<iostream>
using namespace std;
#define N 4
int main(){
	int maze[N][N]={
	{1,0,0,0,0,0
	}};
	solve(maze);
	return 0;
}
bool solveMaze(int maze[N][N]){
	int sol[N][N]={0};
	
	if(!solveMazeUtil(maze,0,0,sol)){
		cout<<"No solution!";
		return false;
	}
	cout<<"Solution";
	print(maze);
	return true;
}
bool solveMazeUtil(int maze[N][N],int x,int y,int sol[N][N]){
	if(x==N-1 && y==N-1 && maze[x][y]==1){
		sol[x][y]=1;
		return true;}
	
	if(isSafe(maze,x,y)){
		if(sol[x][y]==1){
			return false;
		}
	
	
	sol[x][y]=1;
	
	if(solveMazeUtil(maze,x+1,y,sol)){
		return true;
	}
	if(solveMazeUtil(maze,x,y+1,sol)){
		return true;
	}
	if(solveMazeUtil(maze,x,y-1,sol)){
		return true;
	}
	if(solveMazeUtil(maze,x-1,y,sol)){
		return true;
	}
	
	sol[x][y]=0;
	return false;
}
return false;
}

bool isSafe(int maze[N][N],int x,int y){
	return(x>=0 && x<N && y>=0 && y<N && mazr[x][y]==1);
}
