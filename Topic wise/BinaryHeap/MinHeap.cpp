#include<iostream>
using namespace std;
class Heap{
	public:
		int arr[100];
		int size=0;
		
		void insert(int value){
			size++;
			arr[size]=value;
			
			int i=size;
			
			while(i>1){
				int parent=i/2;
				if(arr[parent]>arr[i]){
					swap(arr[parent],arr[i]);
					i=parent;
				}
				else{
					break;
				}
			}
		}
 	void Delete(){
			if(size==0){
				cout<<"NO way "<<endl;
				return;
			}
			int value=arr[1];
			arr[1]=arr[size];
			size--;
			int i=1;
			while(true){
				int left=i*2;
				int right=i*2+1;
				int smallest=i;
				
				if(left<=size && arr[left]<arr[smallest]){
					smallest=left;
				}
				if(right<=size && arr[right]<arr[smallest]){
					smallest=right;
				}
				if(smallest==i){
					break;
				}
				swap(arr[i],arr[smallest]);
				i=smallest;
			}
		}		void print() {
    for (int i = 1; i <=size; i++) cout <<  arr[i] << " ";
    cout << endl;
}
};

int main() {
	Heap h1; 
	
    h1.insert(20);
    h1.insert(15);
    h1.insert(30);
	h1.insert(10);
    h1.insert(40);
    h1.print();
    cout<<endl;
    h1.Delete();
    h1.print();
}
