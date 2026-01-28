#include<iostream>
using namespace std;

void Merge(int arr[],int low ,int mid ,int high){
	int i=low;
	int j=mid+1;
	int k=0;
	int temp[high-low+1];
	while(i<=mid && j<=high){
		if(arr[i]<arr[j]){
			temp[k]=arr[i];
			i++;
			k++;
		}
		else{
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
		while(j<=high){
		temp[k]=arr[j];
		j++;
		k++;
	}
	int m=0;
	for(int t=low;t<=high;t++){
		arr[t]=temp[m];
		m++;
	}
}
void MergeSort(int arr[],int low,int high){
	if(low<high){
		int mid=low+(high-low)/2;
		MergeSort(arr,low,mid);
		MergeSort(arr,mid+1,high);
		Merge(arr,low ,mid,high);
	}
}
int main(){
	int arr1[]={1,4,9,2,5};
	int arr2[]={7,42,10,22,15};
	int arr3[10];
	int w=sizeof(arr1)/sizeof(arr1[0]);
	
	int i=0;
	while(i<w){
		arr3[i]=arr1[i];
		i++;
	}
	
	int k=0;
	while(i<10){
		arr3[i]=arr2[k];
		i++;
		k++;
	}
	cout<<"Before Merge(add arr1 and arr2):"<<endl;
	for(int i=0;i<10;i++){
		cout<<arr3[i]<<" ";
	}
	cout<<endl;
	int n=sizeof(arr3)/sizeof(arr3[0]);
	cout<<"After Merge:"<<endl;
	MergeSort(arr3,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr3[i] <<" ";
	}
}