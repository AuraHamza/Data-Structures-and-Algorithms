#include<iostream>
using namespace std;
void print(char* C){
	while(C!='\0'){
		cout<<C;
		C++;
	}
	cout<<endl;
}
int main(){
	char C[20]="Hamza";
	print(C);
}
