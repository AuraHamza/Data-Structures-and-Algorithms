#include<iostream>
using namespace std;

void BubbleSort(int arr[],int n){
	bool swapped;
	for(int i=0;i<n-1;i++){
		swapped=false;
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				swapped=true;
			}
		}
		if(!swapped) break;
	}
}
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;
    BubbleSort(arr, n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
