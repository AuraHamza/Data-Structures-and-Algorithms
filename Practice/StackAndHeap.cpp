#include<iostream>
using namespace std;
int main(){
	int stack;
	cout<<"Enter a numner for stack memoery: ";
	cin>>stack;
	
	int* heap=new int;
	cout<<"Enter a number for Heap memeory:";
	cin>>*heap;
	
	cout<<"Stack value: "<<stack<<endl;
	cout<<"Heap value: "<<*heap<<endl;
	delete heap;
	return 0;
}
