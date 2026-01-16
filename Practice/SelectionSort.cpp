#include<iostream>
using namespace std;
int selectionSort(int arr[],int n ){
	int minIndex;
	for(int i=0;i<n-1;i++){
		minIndex=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[minIndex]){
				minIndex=j;
			}
		}
		swap(arr[i],arr[minIndex]);

	}
}
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;
    selectionSort(arr, n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}

