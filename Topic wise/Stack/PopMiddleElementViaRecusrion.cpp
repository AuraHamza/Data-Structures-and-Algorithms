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

void Delete(Stack &s,int mid,int size,int n){
	if(n==mid){
		s.pop();
		return ;
	}
	int temp=s.pop();
	Delete(s,mid,size,n+1);
	s.push(temp);
	
}
void display(Stack s){
	while(!s.isEmpty()){
		int val=s.pop();
		cout<<val<<" ";
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

    Delete(s,3,5,1);

    cout << "After deleting middle element: ";
    display(s);
    cout << endl;
}