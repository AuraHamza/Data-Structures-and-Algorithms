#include<iostream>
using namespace std;
int LinearSearch(int arr[],int n,int key,int &count){
	for(int i=0;i<n;i++){
		count++;
		if(arr[i]==key){
			return i;
		}
	}
		return-1;
}

int main(){
	int count=0;
	int arr[] = {45, 12, 78, 34, 23, 89, 10};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key=34;
	int result=LinearSearch(arr, n, key,count);	
	if(result!=-1){
	cout<<"element fount at index: "<<result<<endl;
	}
	else {
		cout<<"not found!"<<endl;
	}
	cout<<"Total comparison: "<<count<<endl;
	return 0;
}
