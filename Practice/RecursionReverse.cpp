#include<iostream>
using namespace std;
void ReverseArr(int arr[],int n,int i){
	if(n==i){
		cout<<"Array reversed;";
		return;
	}
	swap(arr[i],arr[n-i-1]);
	ReverseArr(arr,n,i+1);
}
void Print(int arr[],int n){
	if(n>=0){
		cout<<arr[n-1];
		Print(arr,n-1)
	}
}
int main(){
	int arr[]={1,2,3,4};
	int n=sizeof(arr)/(sizeof(arr[0]));
	ReverseArr(arr,n,0);
	Print(arr,n);
	

}
