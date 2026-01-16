#include<iostream>
using namespace std;
void BinarySort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		bool isSwaped=false;
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				isSwaped=true;
			}
		}
		if(!isSwaped){
			return;
		}
	}
}

void SelectionSort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int small=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[small]){
				small=j;
			}
		}
		swap(arr[i],arr[small]);
	}
}
void InsertionSort(int arr[],int n){
	for(int i=1;i<n;i++){
	int curr=arr[i];
	int pre=i;
	while(pre>=0 && arr[pre]>curr){
		arr[pre+1]=arr[pre];
		pre--
	}
	arr[pre+1]=curr;
	}
}
void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[]={34,1,0,23,6,1};
	int n=6;
	print(arr,n);
	
}
