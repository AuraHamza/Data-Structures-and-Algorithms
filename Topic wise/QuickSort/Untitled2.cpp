#include<iostream>
using namespace std;
int Median(int arr[],int low,int high){
	int mid=(high-low)/2;
	int x=arr[low];
	int y=arr[high];
	int z=arr[mid];
	int min=0;     
	
	          
//	for max
	          
	if(x>max){
	 max=x; 
	 }else if(y>max){ 
	 max=y;
	  } else 
	  {
	   max=mid;
	    }
//	for min
	if(x<min)

		
		min=y;
	}
	else {
		min=mid;
	}
	
//	median
	if(x==max && y==min || y==max && x==min){
		return mid;
	
	
	}else if(x==max && mid==min || x==min && mid==max){
		return mid;
	}
	return -1;
}

int main(){
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	int ans=Median(arr,0,n-1);
	cout<<ans;
}