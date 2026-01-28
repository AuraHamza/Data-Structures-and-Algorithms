#include<iostream>
using namespace std;

void Insert(int headp[],int &size,int value){
	
	int size =0;
	size++;
	heap[size]=value;
	
	int i=size;
	while(i<size){
		int parent=i/2;
		if(heap[parent]<heap[i]){
			swap(heap[parent],heap[i]);
			i=parent;
		}else{
			return;
		}
	}
}

int delete(int heap[],int &size){
	if(size==0){
		cout<<"Empty ha bhai";
		return;
	}
	int maxValue=heap[1];
	int heap[1]=heap[size];
	size--;
	int i=1
	while(i<size){
		int leftchild=2*i;
		int rightchild=2*i+1;
		if(leftchild<size && heap[i]<heap[leftchild]){
			swap(heap[i],heap[leftchild]);
			i=leftchild;		
			}
			else if(rightchild<size && heap[i]<heap[rightchild]){
				swap(heap[i],hea[rightchild]);
				i=rightchild;
			}
			else{
				return;
			}
	}
	return macValue[i];
	
}