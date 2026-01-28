#include <iostream>
using namespace std;

void CountingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

  
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

  
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

   
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}


void RadixSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        CountingSort(arr, n, exp);
}


void MergeArray(int array1[], int array2[], int n, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < n) {
        if (array1[i] <= array2[j]) {
            merged[k++] = array1[i++];
        } else {
            merged[k++] = array2[j++];
        }
    }

    while (i < n)
        merged[k++] = array1[i++];

    while (j < n)
        merged[k++] = array2[j++];
}


void PrintArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        cout << " " << array[i] << " ";
    cout << endl;
}


int main() {
    int n = 10;

    int array1[n] = {12, 19, 14, 1, 18, 6, 7, 13, 5, 10};
    int array2[n] = {9, 2, 4, 17, 8, 11, 3, 20, 15, 16};


    RadixSort(array1, n);
    RadixSort(array2, n);

    cout << "Sorted Array1: " << endl;
    PrintArray(array1, n);

    cout << "Sorted Array2: "<<endl;
    PrintArray(array2, n);

    cout << "Now Merging the Two Sorted Arrays:" <<endl;
    int merged[2*n];
    MergeArray(array1, array2,n,merged);

    PrintArray(merged,2*n);

    return 0;
}
