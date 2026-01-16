#include<iostream>
using namespace std;

int bubbleSort(int arr[],int n){
	int comp=0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			comp++;
			if (arr[j]>arr[j+1]){
			swap(arr[j],arr[j+1]);
		    }
		}
	}
		return comp;
}
int selectionSort(int arr[],int n){
	int comp=0;
	for(int i=0;i<n-1;i++){
		int minIndex=i;
		int j;
		for(j=i+1;j<n;j++){
			comp++;
			if(arr[i]<arr[minIndex]){
				minIndex=j;	
				
			}
		}
		swap(arr[j],arr[minIndex]);
	}
	return comp;
}

int insertionSort(int arr[],int n){
	int comp=0;
	for(int i=1;i<n;i++){
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key){
			comp++;
			if(arr[j]>key){
				arr[j+1]=arr[j];
				j--;
			}else{
				break;
			}
		}
		arr[j+1]=key;
   }
   return comp;
}
int shellSort(int arr[],int n){
	int comp=0;
	for(int gap=n/2;gap>0;gap/=2){
		for(int i=gap;i<n;i++){
			int temp= arr[i];
			int j=i;
			while(j>=gap){
				comp++;
				if(arr[j-gap]>temp){
					arr[j]=arr[j-gap];
					j-=gap;
				}
				else{
					break;
				}
			}
			arr[j]=temp;
		}
	}
	return comp;
}
void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){
const int smallSize = 20;
    int arrSmall[smallSize] = {34, 7, 23, 32, 5, 62, 78, 1, 90, 45, 12, 17, 39, 8, 26, 55, 43, 19, 88, 50};

    cout << "=== Sorting 20-element array ===" << endl;
    printArray(arrSmall, smallSize);

    int arrBubble[smallSize], arrInsertion[smallSize], arrSelection[smallSize], arrShell[smallSize];
    for(int i=0; i<smallSize; i++) {
        arrBubble[i] = arrSmall[i];
        arrInsertion[i] = arrSmall[i];
        arrSelection[i] = arrSmall[i];
        arrShell[i] = arrSmall[i];
    }
     int bubbleComp = bubbleSort(arrBubble, smallSize);
    cout << "\nBubble Sorted: ";
    printArray(arrBubble, smallSize);
    cout << "Bubble Comparisons: " << bubbleComp << endl;

    int insertionComp = insertionSort(arrInsertion, smallSize);
    cout << "\nInsertion Sorted: ";
    printArray(arrInsertion, smallSize);
    cout << "Insertion Comparisons: " << insertionComp << endl;

    int selectionComp = selectionSort(arrSelection, smallSize);
    cout << "\nSelection Sorted: ";
    printArray(arrSelection, smallSize);
    cout << "Selection Comparisons: " << selectionComp << endl;

    int shellComp = shellSort(arrShell, smallSize);
    cout << "\nShell Sorted: ";
    printArray(arrShell, smallSize);
    cout << "Shell Comparisons: " << shellComp << endl;


    
    const int largeSize = 100;
    int arrLarge[largeSize] = {
        34,7,23,32,5,62,78,1,90,45,12,17,39,8,26,55,43,19,88,50,
        66,11,27,70,49,2,82,31,14,60,73,36,6,95,84,29,41,18,54,21,
        13,80,24,9,3,92,56,33,47,22,10,40,77,30,4,61,86,51,28,67,
        35,48,25,16,75,37,59,20,38,53,44,65,79,46,15,85,72,64,42,52,
        57,74,63,71,58,68,81,83,87,69,76,89,94,96,91,98,99,97,100, 0
    };

    cout << "\n=== Sorting 100-element array ===" << endl;
 
    int arrB[largeSize], arrI[largeSize], arrS[largeSize], arrSh[largeSize];
    for(int i=0; i<largeSize; i++) {
        arrB[i] = arrLarge[i];
        arrI[i] = arrLarge[i];
        arrS[i] = arrLarge[i];
        arrSh[i] = arrLarge[i];
    }

    bubbleComp = bubbleSort(arrB, largeSize);
    insertionComp = insertionSort(arrI, largeSize);
    selectionComp = selectionSort(arrS, largeSize);
    shellComp = shellSort(arrSh, largeSize);

    cout << "\nBubble Comparisons (100 elements): " << bubbleComp << endl;
    cout << "Insertion Comparisons (100 elements): " << insertionComp << endl;
    cout << "Selection Comparisons (100 elements): " << selectionComp << endl;
    cout << "Shell Comparisons (100 elements): " << shellComp << endl;

    return 0;
   
}
