#include<iostream>
using namespace std;

int InsertSort(int arr[],int n){
	for(int i=1;i<n;i++){
		int key=arr[i];
		int j=i-1;
		while(j>=0 && j[arr]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
int main(){
	int myarr[]={9,5,1,4,3,14,119};
	int n =sizeof(myarr)/sizeof(myarr[0]);
	for(int i=0;i<n;i++){
		cout<<myarr[i]<<" ";
	}
	InsertSort(myarr,n);
	cout<<endl;
	cout<<"After Sorting: "<<endl;
	for(int i=0;i<n;i++){
		cout<<myarr[i]<<" ";
	}
}
