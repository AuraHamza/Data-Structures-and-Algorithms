#include<iostream>
using namespace std;

class CircularQueue{
	public:
	int front,rear;
	int arr[5];
	int capacity;
	
		CircularQueue(){
			front=-1;
			rear=-1;
			capacity=5;
		}
		bool isEmpty(){
			return (front==-1 && rear==-1);
		}
		void enqueue(int value){
			if((rear+1)%capacity==front){
				cout<<"Stack Overflow";
				return;
			}
			if(front==-1 && rear==-1){
				front=rear=0;
				arr[rear]=value;
				return;
			}
			else{
				rear=(rear+1)%capacity;
				arr[rear]=value;
			}
				
		}
		void dequeue(){
			if(isEmpty()){
				cout<<"Stack Underflow";
				return;
			}
			if((front==rear)){
				front=rear=-1;
				return;
			}
			else{
				front=(front+1)%capacity;
			}
		}
		
	  void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
     int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }
};
int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<"After Entering all values"<<endl;
    q.display();
    
    
    q.dequeue();
    q.dequeue();
cout<<"After Deququqing all values"<<endl;
    q.display();

    q.enqueue(60);
    q.enqueue(70);
cout<<"After Enqueing all values"<<endl;
    q.display();

    cout << "Front element: " << q.getFront() << endl;

    return 0;
}
