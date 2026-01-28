#include<iostream>
using namespace std;
class Stack{
	int arr[100];
	int top=-1;
	public:
		void push(int value){
			if(isfull()){
				cout<<"Stack overflow";
				return;
			}
			top++;
			arr[top]=value;
		}
		int pop(){
			if(isEmpty()){
				cout<<"Stack Underflow";
				return -1;
			}
			int a=arr[top];
			top--;
			return a;
		}
		int peek(){
			if(isEmpty()){
				cout<<"Stack UnderFlow";
				return -1;
			}
			return arr[top];
		}
		bool isfull(){
			return (top==99);
		}
		bool isEmpty(){
			return top==-1;
		}
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    cout << "Top element: " << s.peek() << endl;
    cout << "Popped element: " << s.pop() << endl;
    cout << "Top now: " << s.peek() << endl;

    return 0;
}