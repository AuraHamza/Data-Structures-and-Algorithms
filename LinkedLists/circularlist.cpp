#include<iostream>
using namespace std;

class Node{
	public: 
	int data;
	Node* next;
	
	Node(int value){
		data=value;
		next=NULL;
	}
};
class CircularLinkedlist{
	public: 
	Node* head;
	Node* tail;
	
	CircularLinkedlist(){
		head=NULL;
		tail=NULL;
	}
	//Insertion
	void Insertathead(int value){
		Node* newNode=new Node(value);
		if(head==NULL){
			head=tail=newNode;
			newNode->next=head;
			return;
		}
		tail->next=newNode;
		newNode->next=head;
		head=newNode;
	}
	void InsertAtTail(int value){
		Node* newNode=new Node(value);
		if(head==NULL){
			head=tail=newNode;
			newNode->next=head;
			return;
		}
		tail->next=newNode;
		newNode->next=head;
		tail=newNode;
	}
	void InsertAtPosi(int value,int posi){
		Node* newNode=new Node(value);
		if(head==NULL){
			head=tail=newNode;
			newNode->next=head;
			return;
		}
		Node* curr=NULL;
		Node* temp=head;
		for(int i=0;i<posi && temp!=NULL;i++){
			curr=temp;
			temp=temp->next;
		}
		curr->next=newNode;
		newNode->next=temp;
	}
//Deletion
void deleteFronhead(){
	Node* temp=head;
	if(head==NULL){
		return;
	}
	head=temp->next;
	temp->next=NULL;
	tail->next=head;
	delete temp;
}
void deletefromtail(){
	Node* temp=head;
	Node* curr=NULL;
	if(head==NULL){
		return;
	}
	while(temp->next!=tail){
		temp=temp->next;
	}
	curr=tail;
	tail=temp;
	tail->next=head;
	temp->next=NULL;
	delete curr;
}
void deleteFromPosi(int posi){
	if(head==NULL){
		return;
	}
	Node* curr=NULL;
	Node* temp=head;
	for(int i=0;i<posi && temp!=NULL;i++){
			curr=temp;
			temp=temp->next;
		}
		curr->next=temp->next;
		temp->next=NULL;
		delete temp;
	}
};
