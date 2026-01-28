#include<iostream>
using namespace std;
int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int i=low-1;
	
	for(int j=low;j<high;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	i++;//here i++ and in linked list no increment bcz in linked list i start from head or u can say 0th index, but in array it starts from -1th index
	swap(arr[i],arr[high]);
	return i;
}
void QuickSort(int arr[],int low,int high){
	if(low<high){
	int pivot=partition(arr,low,high);
	QuickSort(arr,low,pivot-1);
	QuickSort(arr,pivot+1,high);
}
}
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    QuickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}