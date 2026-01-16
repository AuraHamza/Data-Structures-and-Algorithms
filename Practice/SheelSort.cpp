#include<iostream>
using namespace std;

int shellSort(int arr[],int n ){
	for(int gap=n/2;gap>0;gap/=2){
		for(int i=gap;i<n;i++){
			int temp=arr[i];
			int j;
			for( j=i; j>=gap && arr[j-gap]>temp;j-=gap){
				arr[j]=arr[j-gap];
			}
			arr[j]=temp;
		}
	}
}
int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = 5;
    shellSort(arr, n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
