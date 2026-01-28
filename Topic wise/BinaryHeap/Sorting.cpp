#include <iostream>
using namespace std;

// Heapify function for min-heap
void heapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && heap[left] < heap[smallest])
        smallest = left;

    if(right < n && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(heap, n, smallest);
    }
}

// Build min-heap
void buildHeap(int heap[], int n) {
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(heap, n, i);
}

// Heap sort using min-heap
void heapSortSubarray(int A[], int st, int ed) {
    int n = ed - st + 1;

    // Copy subarray into temporary array
    int* heap = new int[n];
    for(int i = 0; i < n; i++)
        heap[i] = A[st + i];

    // Build min-heap
    buildHeap(heap, n);

    // Extract elements from heap and put back in original array
    for(int i = 0; i < n; i++) {
        A[st + i] = heap[0];  // smallest element
        swap(heap[0], heap[n - 1 - i]); // move last element to root
        heapify(heap, n - 1 - i, 0);    // heapify reduced heap
    }

    delete[] heap;
}

// Function to print array
void printArray(int A[], int N) {
    for(int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
}

// Main
int main() {
    int A[] = {9, 4, 7, 1, 8, 3, 2};
    int N = sizeof(A)/sizeof(A[0]);
    int st = 2, ed = 5;

    cout << "Original array: ";
    printArray(A, N);

    heapSortSubarray(A, st, ed);

    cout << "Array after sorting subarray [" << st << ".." << ed << "]: ";
    printArray(A, N);

    return 0;
}
