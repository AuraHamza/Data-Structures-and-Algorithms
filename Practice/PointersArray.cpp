#include<iostream>
using namespace std;
int main(){
	int A[]={2,3,5,4,1};
	cout<<"Address: "<<A<<endl;
	cout<<"Address: "<<&A[0]<<endl;
	cout<<"Address: "<<&A<<endl;
	cout<<"Address: "<<A+1<<endl;
	cout<<"Value: "<<*A<<endl;
	cout<<"Value: "<<A[0]<<endl;
} 
