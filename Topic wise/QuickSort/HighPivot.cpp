#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int i=low;
	int j=high-1;
	while(i<j){
		while(arr[i]<=pivot && i<=high){
			i++;
			
		}
		while(arr[j]>pivot && j>=low){
			j--;
			
		}
		if(i<j){
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i],arr[high]);
	return i;
}
void QuickSort(int arr[],int low, int high){
	if(low<high){
		int pivot=partition(arr,low,high);
		QuickSort(arr,low,pivot-1);
		QuickSort(arr,pivot+1,high);
	}
}
int main(){
	int arr[]={4,15,16,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
	QuickSort(arr,0,n-1);
	cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
