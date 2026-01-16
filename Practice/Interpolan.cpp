#include<iostream>
using namespace std;

int interpolationSearch(int arr[],int n,int key, int &count){
	int low=0 ,high=n-1;
	while(low<=high && key>=arr[low] && key<=arr[high]){
		count++;
	if (arr[low] == arr[high]) {
            if (arr[low] == key)
                return low;
            else
                return -1;
        }

 int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]);
			count++;
			if(arr[pos]==key){
				return pos;
			}
			else if(arr[pos]<key)
			{
				low=pos+1;
			}
			else {
				high =pos-1;
			}
			return -1;
	}
}
int main() {
    int arr[] = {100, 200, 300, 400, 500, 600, 700, 800};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key, count, index;

    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\nEnter element to search: ";
    cin >> key;

    index = interpolationSearch(arr, n, key, count);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    cout << "Comparisons made: " << count << endl;

    return 0;
}

