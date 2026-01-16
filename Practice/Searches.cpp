#include <iostream>
using namespace std;

int linearSearch(int arr[],int n,int key) {
    for (int i=0;i<n;i++) {
        if (arr[i]==key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[],int n,int key) {
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if (arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}


int interpolationSearch(int arr[],int n,int key) {
    int low=0,high=n-1;
    while(low<=high && key>=arr[low] && key<=arr[high]) {
        if(low==high){
            if(arr[low]==key) {
			return low;
			}
		
            return -1;
        }
        int pos=low+((key-arr[low])*(high-low))/(arr[high]-arr[low]);
        if(arr[pos]==key){
        	return pos;
		}
            
        if (arr[pos] < key){
        	low=pos+1;
		}
            
        else{
        	high=pos-1;
		}
            
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;

    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nEnter number to search: ";
    cin >> key;

    int l = linearSearch(arr, n, key);
    int b = binarySearch(arr, n, key);
    int inter = interpolationSearch(arr, n, key);

    cout <<"Search Results";
{
    if (l!=-1){
        cout<<"\nLinear Search: Found at index "<<l;
    } else {
        cout<<"\nLinear Search: Not Found";
    }
}

{
    if (b != -1) {
        cout << "\nBinary Search: Found at index " << b;
    } else {
        cout << "\nBinary Search: Not Found";
    }
}

{
    if (inter !=-1) {
        cout <<"\nInterpolation Search: Found at index " << inter;
    } else {
        cout <<2"\nInterpolation Search: Not Found";
    }
}

    return 0;
}

