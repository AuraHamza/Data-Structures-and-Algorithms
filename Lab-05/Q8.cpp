#include<iostream>
using namespace std;

int LinearSearch(int arr[],int n, int key){
	for(int i=0; i<n;i++){
		if(arr[i]==key){
			return i;
		}
		return -1;
	}
}
int main(){
    int arr[] = {3, 8, 5, 12, 7, 9}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int key = 5; 
    int index = LinearSearch(arr, n, key);

    if (index!=-1) {
        cout<<"Value "<<key<<"not found at index"<<index<<endl;
    } else {
        cout<<"Value "<<key<<" found in the array."<<endl;
    }
    return 0;
}
