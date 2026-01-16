#include<iostream>
using namespace std; 
int getNetGap(int gap){
	gap=(gap*10)/13;
	if (gap<1){
		return 1;
	}else{return gap;}
}
void combSort(int arr[],int n){
	int gap=n;
//	bool swapped=true;
	while(gap!=1   ){
		gap=getNetGap(gap);
//		swapped =false;
		for(int i=0;i<n-gap;i++){
			if(arr[i]>arr[i+gap]){
				swap(arr[i],arr[i+gap]);
//				swapped= true;
			}
		}
	}
}
int main() {
    int arr[] = {8, 4, 1, 5};
    int n = 4;
    combSort(arr, n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";}
    
