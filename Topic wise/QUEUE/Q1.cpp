#include<iostream>
using namespace std;

class Queue{
	int rear,front;
	int arr[10];
	public:
	Queue(){
		rear=-1;
		front=-1;
	}	
	void Equeue(int value){
		if(isFull()){
			cout<<"The Queue is FULL";
			return;
		}
		if(isEmpty()){
			front++;
			rear++;
			arr[rear]=value;
			cout<<"Value has been inserted!"<<endl;
			return;
		}
		rear++;
		arr[rear]=value;
	}
	int Dequeue(){
		if(isEmpty()){
			cout<<"The Queue is Empty!";
			return -1;
		}
		int value=arr[front];
		for(int i=front;i<=rear;i++){
			arr[i]=arr[i+1];
		}
		rear--;
		return value;
	}
	int Front(){
		return arr[front];
	}
	bool isEmpty(){
		return (front == -1 || front > rear);
	}
	bool isFull(){
		return rear==9;
	}
	void display(){
		if(isEmpty()){
			cout<<"The Queue is Empty!";
			return;
		}
		for(int i=front;i<=rear;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};
int main(){
	Queue q;
	q.Equeue(2);
	q.Equeue(5);
	q.Equeue(10);
	q.Equeue(11);
	q.Equeue(13);
	q.Equeue(14);
	q.Equeue(16);
	q.Equeue(18);
	q.display();
	q.Dequeue();
	q.display();
	
	
}