#include<iostream>
using namespace std;

bool ispalandrom(int arr[],int i,int j,int n){
	int mid=n/2;
	if(i<mid){
		if(arr[i]==arr[n-j]){
			 if(ispalandrom(arr,i+1, j+1,n)){
			return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}
	return true;
}
int main(){
	int arr[]={1,2,2,1};
	int n=sizeof(arr)/(sizeof(arr[0]));
	bool flag=ispalandrom(arr,0,1,n);
	if(flag==true){
		cout<<"Given array is Palindrom";
	}else{
		cout<<"Given array is not Palindrom";
	}
}
