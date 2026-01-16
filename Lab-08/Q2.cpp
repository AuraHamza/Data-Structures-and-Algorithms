#include<iostream>
using namespace std;

class Node{
	public: 
	string data;
	Node* next;
	
	Node(string value){
		data=value;
		next=NULL;
	}
};

class Stack{
	Node* top;
	public:
		Stack(){
			top=NULL;
		}
		
		void push(string value){
			Node* newNode=new Node(value);
			newNode->next=top;
			top=newNode;
			
		}
		
		void pop(){
			if(isEmpty()){
				cout<<"Stack is Empty.";
			}
			Node* temp=top;
			cout<<temp->data<<"its pop out."<<endl;
			top=top->next;
			delete temp;
		}
		bool isEmpty(){
			if(top==NULL){
				return true;
			}
			return false;
		}
		void display(){
			if(isEmpty()){
				cout<<"Stack is empty.";
				return;
			}
			Node* temp=top;
			cout<<"\nStack elements"<<endl;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
};

int main(){
	Stack s;
	s.push("Google");
	s.push("Facebook");
	s.push("Twitter");
	s.push("LinkedIn");
	s.push("InstaGram");
	s.display();
	s.pop();
	s.pop();
	s.display();
	
}