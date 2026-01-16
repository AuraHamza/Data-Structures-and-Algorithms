#include<iostream>
using namespace std;
class Node{
	public:
    int data;
	Node* next;
	
	Node(){
		data=0;
		next=NULL;
	}
	Node(int value){
		data=value;
		next=NULL;
	}
};
Node* head=NULL;
Node* tail=NULL;

void InsertByValue(int value){
	Node* newNode=new Node(value);
	newNode->next=head;
	head=newNode;
	cout<<value<<", Added"<<endl;
}

void ReverseList(){
	Node* pre=NULL;
	Node* next=NULL;
	Node* curr=head;
	while(curr!=NULL){
		next=curr->next;
		curr->next=pre;
		pre=curr;
		curr=next;
	}
	head=pre;
}
void display(){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
	

int main(){
	InsertByValue(1);
	InsertByValue(2);
	InsertByValue(3);
	InsertByValue(4);
	InsertByValue(5);
	InsertByValue(6);
	
	display();
	ReverseList();
	cout<<"\nAfter reversing the list: "<<endl;
	display();		
	
}
