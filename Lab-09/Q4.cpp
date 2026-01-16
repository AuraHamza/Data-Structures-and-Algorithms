#include<iostream>
using namespace std;
class Queue{
	int front,rear;
	int arr[10];
	int capacity;
	public:
		Queue(){
			front=-1;
			rear=-1;
		}
		void Equeue(int id){
			if(isFull()){
			cout<<"Queue is FuLL"<<endl;
			return;	
			}
			if(isEmpty()){
				rear=front=0;
				arr[rear]=id;
				cout<<id<<")patient add"<<endl;
				return;
			}
				rear++;
				arr[rear]=id;
				cout<<id<<")patient add"<<endl;
			
		}
		int Dequeue(){
			if(isEmpty()){
				cout<<"Queue UnderFlow"<<endl;
				return -1;
			}
			int id=arr[front];
			for(int i=front;i<rear;i++){
				arr[i]=arr[i+1];
			}
			rear--;
			cout<<"patient remove"<<endl;
			return id;
		}
		bool isEmpty(){
			return(front==-1 || front>rear);
		}
		bool isFull(){
			return rear==9;
		}
		void display(){
			if(isEmpty()){
				cout<<"Queue is Empty"<<endl;
				return ;
			}
			for(int i=front;i<=rear;i++){
				cout<<arr[i]<<" ";
			}
		}
};
int main(){
	Queue q;
	q.Equeue(1);
	q.Equeue(2);
	q.Equeue(3);
	q.Equeue(4);
	q.Equeue(5);
	q.Equeue(6);
	q.Equeue(7);
	q.Equeue(8);
	q.Equeue(9);
	q.Equeue(10);
	q.Equeue(1);
	cout<<"Displaying Queue: "<<endl;
	q.display();
	cout<<endl;
	q.Dequeue();
	q.Dequeue();
	cout<<"After Dequing Displaying Queue: "<<endl;
	q.display();
	
}