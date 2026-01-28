#include<iostream>
using namespace std;

void merge(int arr[],int start,int mid,int end){
	int temp[100];
	int i=start;
	int j=mid+1;
	int k=0;
	
	while(i<=mid && j<=end){
		if(arr[i]<arr[j]){
			temp[k]=arr[i];
			i++;
			k++;
		}else{
			temp[k]=arr[j];
			j++;
			k++;
		}
	}
	while(i<=mid){
		temp[k]=arr[i];
		i++;
		k++;
	}
	while(j<=end){
		temp[k]=arr[j];
		j++;
		k++;
	}
	
	for(int t=0;t<k;t++){
		arr[start+t]=temp[t];
	}
}
void mergesort(int arr[],int start,int end){
	if(start<end){
		int mid=(start+end)/2;
		mergesort(arr,start,mid);
		mergesort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}


int main(){
	int arr[]={5,6,3,1};
	
	mergesort(arr,0,3);
	
	for(int i=0;i<4;i++){
		cout<<arr[i]<<" ";
	}
}
