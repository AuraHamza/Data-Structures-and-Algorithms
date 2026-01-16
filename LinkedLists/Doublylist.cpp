#include<iostream>
using namespace std;

class Node{
	public: 
	int data;
	Node* next;
	Node* prev;
	
	Node(int value){
		data=value;
		next=NULL;
		prev=NULL;
	}
};
class DoublyLinkedlist{
	public:
		Node* head
		Node* tail;
	DoublyLinkedlist(){
		head=NULL;
		tail=NULL;
	}
void insertAtHead(int val) {
    Node* newNode = new Node(val);

    if (head == NULL) { 
        head = tail = newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    cout<<"added to head";
}
	void insertAtTail(int value){
		Node* newNode=new Node(value);
		if(head==NULL){
			head=tail=newNode;
		}
	else{
	tail->next=newNode;
	newNode->prev=tail;
	tail=newNode;
	}
void insertByPosi(int value,int posi){
		Node* newNode=new Node(value);
		if(head==NULL && posi==0){
		head=tail=newNode;
		return;
		}
		Node* temp=head;
		Node* p=NULL;
		for(int i=0;i<posi;i++){
			p=temp;
			temp=temp->next;
		}
		if(temp==NULL){
			p->next = newNode;
        newNode->prev = p;
			tail=newNode;
			return;
		}
		p->next=newNode;
		newNode->prev=p;
		temp->prev=newNode;
		newNode->next=temp;
	}
// deletion 
void DeleteFromhead(){
	if(head==NULL){
		return;
	}
	Node* temp =head;
	head=temp->next;
	temp->next=NULL;
	head->prev=NULL;
	delete temp;
}
void DeleteFromtail(){
	if(head==NULL){
		return;
	}
	Node* temp =tail;
	tail=temp->prev;
	temp->prev=NULL;
	tail->next=NULL;
	delete temp;
}
void DeleteByposi(int posi){
	if(head==NULL){
		return;
	}
	Node* temp=head;
	Node* curr=NULL
	Node* p=NULL
	for(int i=0;i<posi && temp!=NULL;i++){
		curr=temp->next;
		p=temp;
		temp=temp->next;
	}
	p->next=temp->next;
	curr->prev=temp->prev;
	delete temp;
}
//
void ReverseList(){
	if(head==NULL){
		head=tail;
		return ;
	}
	Node* temp=head;
	Node* curr=NULL;
	Node* p=NULL;
	while(temp!=NULL){
		curr=temp->next;
		temp->prev=temp->next;
		temp->next=p;
		p=temp;
		temp=curr;
	}
}
//Search value 
bool Search(int val){
		if(head==NULL){
		return false ;
	}
	Node* temp=head;
	while(temp!=NULL){
		if(temp->data==val){
			return true;
		}
		temp=temp->next;
	}
	return false;
}
	
};
