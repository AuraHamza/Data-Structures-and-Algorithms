#include<iostream>
using namespace std;
const int k=9;
void countSort(int arr[], int n){
    int sol[n]={-1};
	int count[10]={0};

	for(int i=0;i<n;i++){
		count[arr[i]]++;
	}
	for(int i=0;i<n;i++){
		cout<<sol[i]<<" ";
	}
	for(int i=1;i<=k;i++){
		count[i] += count[i-1];
	}

	for (int i=n-1;i>=0;i--){
		sol[count[arr[i]]] = arr[i];
	}
	
	for(int i=0;i<n;i++){
		cout<<sol[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int arr[]={2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,9};
	countSort(arr, 17);
}