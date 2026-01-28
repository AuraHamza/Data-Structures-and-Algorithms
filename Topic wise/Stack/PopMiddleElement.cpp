#include<iostream>

using namespace std;
class Stack{
	int arr[10];
	int top;
	
	public:
		Stack(){
		top=-1;
	}
		void push(int value){
			if(top>9){
				cout<<"Stack OverFlow";
				return;
			}
			top++;
			arr[top]=value;
		}
		int pop(){
			if(isEmpty()){
				cout<<"Stack UnderFlow";
				return -1;
			}
			return arr[top--];
		}
		int peek(){
			return arr[top];
		}
		bool isEmpty(){
			return top==-1;
		}
};

void deleteMiddle(Stack &s, int size) {
    int mid = size / 2;
    Stack temp;

    // Move top half to temp until reaching middle
    for (int i = 0; i < mid; i++) {
        temp.push(s.pop());
    }

    // Pop the middle element (delete it)
    s.pop();

    // Push back the elements from temp
    while (!temp.isEmpty()) {
        s.push(temp.pop());
    }
}

void display(Stack s) {

    while (!s.isEmpty()) {
        int val = s.pop();
        cout << val << " ";
    }
}

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Original stack: ";
    display(s);
    cout << endl;

    deleteMiddle(s,5);

    cout << "After deleting middle element: ";
    display(s);
    cout << endl;
}
