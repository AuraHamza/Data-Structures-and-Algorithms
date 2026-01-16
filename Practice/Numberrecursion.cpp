#include<iostream>
using namespace std;

void print(int n,int N){
	int c=n;
	if(n>N){return ;
	}
	print(n+1,N);
	cout<<n<<endl;
}
int main(){
	print(1,4);
}
