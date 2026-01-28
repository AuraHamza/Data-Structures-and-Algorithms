#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i){
	int smallest =i;
	int left=2*i;
	int right=2*i+1;
	
	if(left<=n  && arr[left]<arr[smallest]){
		smallest=left;
	}
	
	if(right<=n  && arr[right]<arr[smallest]){
		smallest=right;
	}
	
	if(smallest!=i){
		swap(arr[smallest],arr[i]);
		heapify(arr,n,smallest);
	}
}

void buildMaxHeap(int arr[],int n){
	for(int i=n/2;i>=1;i--){
		heapify(arr,n,i);
	}
}

void deleteMax(int arr[],int &n){
	arr[1]=arr[n];
	n--;
	heapify(arr,n,1);
}


int kthLargest(int arr[],int n,int k){
	buildMaxHeap(arr,n);
	for(int i=1;i<k;i++){
		deleteMax(arr,n);
	}
	return arr[1];
}

/* Main Function */
int main() {
    int arr[] = {0, 7, 10, 4, 3, 20, 15}; // index 0 unused
    int n = 6;
    int k = 1;

    int result = kthLargest(arr, n, k);
    cout << "K-th Largest element: " << result << endl;

    return 0;
}