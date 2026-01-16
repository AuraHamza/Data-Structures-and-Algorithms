#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter size of Array: ";
	cin>>n;
	
	int stackArr[100];
	cout<<"Enter "<<n<<" elements for stack array:";
	for(int i=0;i<n;i++){
		cin>>stackArr[i];
	}
	cout<<endl;
	//Display Stack
	cout<<"Display Stack Memory Elements: ";
	for(int i=0;i<n;i++){
		cout<<stackArr[i]<<" ";
	}
	
	int* heapArr=new int[n];
	cout<<"\nEnter "<< n <<" elements for Heap array: ";
	for(int i=0;i<n;i++){
		cin>>heapArr[i];
	}
	
	//Display Heap
	cout<<"Display Heap Memory Elements:";
	for(int i=0;i<n;i++){
		cout<<heapArr[i]<<" ";
	}
	delete[] heapArr;
	return 0;
	
}
