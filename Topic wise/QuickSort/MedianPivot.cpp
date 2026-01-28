#include<iostream>
using namespace std;

int partition(int arr[], int low, int high) {

    int mid = (low + high) / 2;

    // -------- FIND MEDIAN OF THREE (low, mid, high) --------
    if(arr[low] > arr[mid]) swap(arr[low], arr[mid]);
    if(arr[mid] > arr[high]) swap(arr[high],arr[mid]);
    if(arr[low] > arr[mid]) swap(arr[low], arr[mid]);
    // now arr[mid] is median

    swap(arr[mid], arr[high]);     // move median to high
    int pivot = arr[high];

    // -------- PARTITION USING WHILE LOOP --------
    int i = low;
    int j = high - 1;   // because pivot is at high

    
	while(i<j) {

        while(arr[i] < pivot) i++;

        while(arr[j] > pivot) j--;

        if(i < j) swap(arr[i], arr[j]);
    }
    // -------- FINAL PIVOT SWAP --------
    swap(arr[i], arr[high]);
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
	int arr[]={4,15,100,16,3};
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
