#include<iostream>
using namespace std;
int getNextGap(int gap){
	gap=(gap*10)/13;
	return (gap<1)?1:gap;
}
void Combsort(int arr[],int n){
	int gap=n;
	bool swapped=true;
	while(gap!=1 || swapped){
		gap=getNextGap(gap);
		swapped=false;
	for(int i=0;i<n-gap;i++){
		if(arr[i]>arr[i+gap]){
			swap(arr[i],arr[i+gap]);
			swapped=true;
		}
	}
}
}
int main() {
    int arr[] = {34, 7, 23, 32, 5, 62, 78, 1, 90, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout <<"Before Sorting: ";
   for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    Combsort(arr, n);
    
    cout <<"After Sorting: ";
     for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

