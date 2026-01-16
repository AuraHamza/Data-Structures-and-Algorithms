#include<iostream>
using namespace std;

void reverse(int arr[],int i,int j,int n){
	int mid=n/2;
	if(i<mid){
	swap(arr[i],arr[n-j]);
	reverse(arr, i+1, j+1, n);
	}
	
}
void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/(sizeof(arr[0]));
	reverse(arr,0,1,n);
	print(arr,n);
	
}

