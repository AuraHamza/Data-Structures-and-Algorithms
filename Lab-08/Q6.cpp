#include<iostream>
using namespace std;

class Queue{
	string s[10];
	int rare;
	int front;
	public:
		Queue(){
			front=0;
			rare=-1;
		}
		void enqueue(string value){
			if(rare>=9){
				cout<<"Queue Overflow"<<endl;
				return;
			}
			rare++;
			s[rare]=value;
		}
		void dequeue(){
			if(rare<0){
				cout<<"Queue UnderFlow"<<endl;
				return;
			}
			cout<<s[front]<<" removed from queue"<<endl;
			
			for(int i=front;i<rare;i++){
				s[i]=s[i+1];
			}
			rare--;
		}
		bool isEmpty(){
			if(rare<front){
				return true;
			}
			return false;
		}
		void display(){
			if(isEmpty()){
				cout<<"Queue is Empty"<<endl;
				return;
			}
			cout<<"Queue element: ";
			for(int i=front;i<=rare ;i++){
				cout<< s[i]<<" ";
			}
			cout<<endl;
		}
};
int main(){
	Queue q;
	q.enqueue("Mehran");
	q.enqueue("Cultus");
	q.enqueue("Corolla");
	q.enqueue("Civic");
	q.display();
	q.dequeue();
	q.dequeue();
	q.display();
}