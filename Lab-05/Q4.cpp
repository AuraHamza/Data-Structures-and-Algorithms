#include<iostream>
using namespace std;

int BubbleSort(int arr[],int n){
	for(int i=1;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}
int main(){
     int arr[]= {2,0,14,43,25,18,1,5,45};
     int n=sizeof(arr)/sizeof(arr[0]);
     
     cout<<"Input Listed: "<<endl;
     for(int i=0;i<n;i++){
     	cout<<arr[i]<<" ";
	 }
	     BubbleSort(arr, n);

	 
     cout<<"\nSorted Listed: "<<endl;
     for(int i=0;i<n;i++){
     	cout<<arr[i]<<" ";
	 }
	 
}
