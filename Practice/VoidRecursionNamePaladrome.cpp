#include<iostream>
using namespace std;

//void ispalandrom(int arr[],int i,int j,int n){
//	int mid=n/2;
//	if(i<mid){
//		if(arr[i]==arr[n-j]){
//			 if(ispalandrom(arr,i+1, j+1,n)){
//			 	cout<<"Is Palidrone";
//				 	return ;
//			}else{
//				cout<<"Not paladrom";
//				return;
//			}
//		}else{
//			return;
//		}
//	}
//	return;
//}
void palandrom(int arr[],int i,int j,int n){
	if(i<n/2){
		if(arr[i]==arr[n-j]){
			return palandrom(arr,i+1,j+1,n);
		}
		cout<<"ispalandrome"<<endl;
	}
	else{
		cout<<"Isnot ";
	}
	return;
}
int main(){
	int arr[]={1,2,2,0,1};
	int n=sizeof(arr)/(sizeof(arr[0]));
	palandrom(arr,0,1,n);
	
}
