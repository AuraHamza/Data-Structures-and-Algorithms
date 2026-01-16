#include<iostream>
using namespace std;
int SumOfElement(int A[], int size){
	int sum=0;
	for(int i=0;i<size;i++){
		 sum+=A[i];
	}
	return sum;
}
int main(){
	int A[]={1,2,3,4,5};
	int size=sizeof(A)/sizeof(A[0]);
int total=	SumOfElement(A,size);
	cout<<"Sum of element= "<<total;
}
