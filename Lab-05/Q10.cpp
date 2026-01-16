#include<iostream>
using namespace std;

int binarysearch(int arr[],int n,int key){
	int low=0 , high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==key){
			return mid;
		}
		else if(arr[mid]<key){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return -1;
}

void BubbleSort(int arr[],int n){
	bool swapped=true;
	for(int i=0;i<n-1;i++){
		swapped =true;
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				swapped=true;
			}
		}
		if(!swapped) break;
	}
}

int main(){
	int n,key;
	cout<<"Enter size of array:";
	cin>>n;
	int arr[n];
	cout<<"Enter elements of array: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<endl;
	cout<<"Enter element u need: ";
	cin>>key;
	cout<<endl;
	BubbleSort(arr,n);
	int result=binarysearch(arr,n,key);
	
	cout<<"After sorting: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	if(result!=-1){
	cout<<"element fount at index: "<<result<<endl;
	}
	else {
		cout<<"not found!"<<endl;
	}
	return 0;
}
