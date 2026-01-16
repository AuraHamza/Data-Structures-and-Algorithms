#include<iostream>
using namespace std;
int main(){
	int a=2147483648;
	int* p;
	p=&a;
	cout<<"Address: "<<p<<"  Value: "<<*p<<endl;
	cout<<"Address: "<<(p+1)<<"  Value: "<<*(p+1)<<endl;
}
