#include <iostream>
using namespace std;

void generateSubsets(int arr[], int n, int index, int subset[], int subsetSize) {
    // Base case: if we've processed all elements
    if (index >= n) {
        cout <<"{";
        for (int i = 0; i < subsetSize; i++) {
            cout << subset[i];
        }
        cout <<"}\n";
        return;
    }



    // ---- Choice 2: Include arr[index] ----
    subset[subsetSize] = arr[index];
    generateSubsets(arr, n, index + 1, subset, subsetSize + 1);
        // ---- Choice 1: Exclude arr[index] ----
    generateSubsets(arr, n, index + 1, subset, subsetSize);
}

int main() {
    int arr[] = {3,1,2}; // input set
    int n = sizeof(arr) / sizeof(arr[0]);
    int subset[100]; // temporary array to hold current subset

    cout << "All subsets:\n";
    generateSubsets(arr, n, 0, subset,0);

    return 0;
}

