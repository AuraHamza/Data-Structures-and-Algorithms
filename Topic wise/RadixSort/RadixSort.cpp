#include<iostream>
using namespace std;

void CountSort(int arr[],int n,int exp){
	int count[10]={0};
	int sol[100];
	
	//add 1 in each place;
	for(int i=0;i<n;i++){
		int digit=(arr[i]/exp)%10;
		count[digit]++;
	}
	
	//add prefix
	for(int i=1;i<10;i++){
		count[i]+=count[i-1];
	}
	
	//make sol output
	for(int i=n-1;i>=0;i--){
		int digit=(arr[i]/exp)%10;
		sol[count[digit]-1]=arr[i];
		count[digit]--;
	}
	//copy back
	for(int i=0;i<n;i++){
		arr[i]=sol[i];
	}
}
void RadixSort(int arr[],int size){
	int maxValue=arr[0];
	for(int i=0;i<size;i++){
		if(maxValue<arr[i]){
			maxValue=arr[i];
		}
	}
	//call count sort
	for(int exp=1;maxValue/exp>0;exp*=10){
		CountSort(arr,size,exp);
	}
	
}
int main(){ 
     int arr[] = {238,9,405,12};
     int size=sizeof(arr)/sizeof(arr[0]);
     
     cout<<"Array NOT sorted: ";
     for(int i=0;i<size;i++){
     	cout<<arr[i]<<" ";
	 }
	 cout<<endl;
	 
	 RadixSort(arr,size);
	 cout<<"Array  sorted: ";
     for(int i=0;i<size;i++){
     	cout<<arr[i]<<" ";
	 }
	 cout<<endl;
}