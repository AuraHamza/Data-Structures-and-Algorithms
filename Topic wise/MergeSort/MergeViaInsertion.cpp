#include <iostream>
using namespace std;

// Insertion sort for a specific range
void insertionSort(int arr[], int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key
        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge two sorted halves
void Merge(int arr[], int start, int mid, int end) {
    int temp[100];
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= end) temp[k++] = arr[j++];

    for (int t = 0; t < k; t++) {
        arr[start + t] = temp[t];
    }
}

// Hybrid Merge Sort (uses insertion sort for small subarrays)
void MergeSort(int arr[], int start, int end) {
    int size = end - start + 1;

    // Use insertion sort for small subarrays
    if (size <= 6) {
        insertionSort(arr, start, end);
        return;
    }

    if (start < end) {
        int mid = start + (end - start) / 2;

        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}

int main() {
    int arr[] = {9, 4, 7, 3, 10, 2, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    MergeSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

