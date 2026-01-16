#include<iostream>

int Max(int arr[],int n){
	int max=0;
	if(n==0){
		return max;
	}
	if(arr[max]<arr[n]){
		max=arr[n];
	}
	return Max(arr,n-1);
}
int main(){
	int arr[]={0,1,2,3,4,5};
	int n=sizeof(arr)/(sizeof(arr[0]));
	int max=Max(arr,n);
	cout<<max;
}
