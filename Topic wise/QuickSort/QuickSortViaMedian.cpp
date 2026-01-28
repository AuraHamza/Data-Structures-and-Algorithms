#include<iostream>
using namespace std;
int Median(int arr[],int low,int high){
	int mid=low+(high-low)/2;
	int x=arr[low];
	int y=arr[high];
	int z=arr[mid];
	int min=arr[low];     
	int max=arr[high];
	          
//	for max          
	if(x>max){
	 max=x; 
	 }else if(y>max){ 
	 max=y;
	  } else if(z>max){
	   max=z;
	    }
//	for min
	if(x<min){
		min=x;
	}else if(y<min){
		min=y;
	}else if (z<min){
		min=z;
	}
	
//	median
	if((x==max && y==min) || (y==max && x==min)){
		return z;
	
	
	}else if((x==max && z==min) || (x==min && z==max)){
		return y;
	}
	else {
		return x;
	}
	
}

int partition(int arr[],int low ,int high){
	int pivot=Median(arr,low,high);
	swap(arr[low],pivot);

	int i=low+1;
	int j=high;
	
	while(i<=j){
		while(arr[i]<=pivot && i<high){
			i++;
		}
		while(arr[j]>pivot && j>low){
			j--;
		}
		if(i<j){
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[low],arr[j]);
		return j;
}
void QuickSort(int arr[],int low,int high){
	if(low<high){
		int pivot=partition(arr,low,high);
		QuickSort(arr,low,pivot-1);
		QuickSort(arr,pivot+1,high);
	}
}
int main(){
	int arr[]={10,12,5,98,100};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	cout<<"Before:"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	QuickSort(arr,0,n-1);
	cout<<"After:"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
//	int ans=Median(arr,0,n-1);
//	cout<<ans;
}