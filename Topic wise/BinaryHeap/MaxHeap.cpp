#include<iostream>
using namespace std;

class Heap{
	public:
		int arr[100];
		int size;
		Heap(){
			arr[0]=-1;
			size=0;
		}
		
		void insert(int value){
			size++;
			arr[size]=value;
			
			int i=size;
			while(i>1){
				int parent=i/2;
				if(arr[parent]<arr[i]){
					swap(arr[parent],arr[i]);
					i=parent;
				}
				else{
					return;
				}
			}	
		}
		void Delete() {
    if (size == 0) {
        cout << "Heap is empty";
        return;
    }

    // Step 1: Move last element to root
    arr[1] = arr[size];
    size--;

    int i = 1;

    // Step 2: Heapify-down
    while (true) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        // Check left child
        if (left <= size && arr[left] > arr[largest]) {
            largest = left;
        }

        // Check right child
        if (right <= size && arr[right] > arr[largest]) {
            largest = right;
        }

        // If root is already larger than both children ? stop
        if (largest == i) {
            break;
        }

        // Otherwise swap with the larger child
        swap(arr[i], arr[largest]);
        i = largest;
    }
}

		
		void print(){
			for(int i=1;i<=size;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};

int main(){
	Heap h1;
	h1.insert(53);
	h1.insert(60);
	h1.insert(43);
	h1.insert(65);
	h1.insert(63);
	h1.insert(70);
	h1.print();
	h1.Delete();
	h1.print();
	
}