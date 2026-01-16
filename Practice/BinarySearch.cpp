#include<iostream>
using namespace std;
 
int BinarySearch(int arr[],int n,int key,int &count){
	int low=0, high=n-1;
	while(low<=high){
		count++;
		int mid=low+(high-low)/2;
		if(arr[mid]==key){
			return mid;
		}
		else if(arr[mid]<key){
		 low=mid+1;
		}
		else {
			high=mid-1;
		}
	}
	return -1;
}
int main(){
	int count=0;
	int arr[] = {5, 15, 25, 35, 45, 5, 65, 75, 85};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key=85;
	int result=BinarySearch(arr, n, key,count);	
	if(result!=-1){
	cout<<"element fount at index: "<<result<<endl;
	}
	else {
		cout<<"not found!"<<endl;
	}
	cout<<"Total comparison: "<<count<<endl;
	return 0;
}


