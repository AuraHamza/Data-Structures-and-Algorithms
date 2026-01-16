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

class Linkedlist{
	public: 
	Node* head;
	Node* tail;
	
	Linkedlist(){
		head=NULL;
		tail=NULL;
	}
	//Insertion 3 ways
	void insertAthead(int value){
		Node* newNode=new Node(value);
		newNode->next=head;
		head=newNode;
	}
	void insertAtTail(int value){
		Node* newNode=new Node(value);
		if(head==NULL){
			head=newNode;
		}
	else{
	tail->next=newNode;
	tail=newNode;
	}
	}
	void insertByPosi(int value,int posi){
		Node* newNode=new Node(value);
		if(posi==0 ||head==NULL){
			newNode->next=head;
			head=newNode;
			return;
		}
		Node* temp=head;
		for(int i=0;i<posi;i++){
			temp=temp->next;
		}
		newNode->next=temp->next;
		temp->next=newNode;
	}
	
//	Deletion 3 Ways
	void RemoveFromHead(){
		if(head==NULL){
			return ;
		}
		Node* temp=head;
		head=temp->next;
		temp->next=NULL;
		delete temp;
	}
	void RemoveFromTail(){
			if(head==NULL){
			return ;
		}
		Node* temp=head;
		Node* pre=NULL;
		while(temp->next!=NULL){
			pre=temp;
			temp=temp->next;
			
		}
		tail=pre;
		tail->next=NULL;
		delete temp;
	}
	void RemoveFromValue(int value){
			if(head==NULL){
			return ;
		}
	
		Node* temp=head;
		Node* pre=NULL;
		if(temp->data==value){
			head=temp->next;
			delete temp;
			return;
		}
		while(temp!=NULL){
			if(temp->data==value){
				pre->next=temp->next;
				delete temp;
				return;
			}
			pre=temp;
			temp=temp->next;
	   }
	   cout<<"Value Not found!";
	}
//	Display
void Display(){
		if(head==NULL){
			cout<<"List is empty!";
			return ;
		}
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}		
	cout<<"NULL";
}

// Reverse of list 
void Reverse(){
		if(head==NULL){
			return ;
		}
	Node* temp=head;
	Node* curr=head;
	Node* prev=NULL;
	while(temp!=NULL){
		curr->next=prev;
		curr=temp->next;
		prev=temp;
		temp=curr;
	}	
	head=prev;
}
// Finding middle
int MiddleValue(){
	Node* slow=head;
	Node* fast=head;
	while(fast->next!=NULL ||fast!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow->data;
}
//Merege list 
Node* Merge(Node* h1,Node* h2){
	if(h1==NULL){
		return h2;
    }
   	if(h2==NULL){
		return h1;
    }
    
    Node* head=NULL;
    if(h1->data<h2->data){
    	head=h1;
    	h1=h1->next;
	}
	else{
		head=h2;
		h2=h2->next;
	}
	Node* temp=head;
	while(h1!=NULL && h2!=NULL){
		if(h1->data<h2->data){
			temp->next=h1;
			h1=h1->next;
		}
		else{
			temp->next=h2;
			h2=h2->next;
		}
		temp=temp->next;
	}
	
	if(h1!=NULL){
		temp->next=h1;
	}
	if(h2!=NULL){
		temp->next=h2;
	}
	return head;
}
//break into sublist after value x
Node* breaklist(Node* head1, int x){
	if(head==NULL){
		return NULL;
	}
	Node* temp=head1;
	Node* pre=NULL;

	while(temp!=NULL){
		if(temp->data==x){
			pre->next=NULL;
			return temp;
		}
		pre=temp;
		temp=temp->next;
	}
	return NULL;
}
};

int main() {
    Linkedlist list;

    // Insert elements
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);

    cout << "Original List: ";
    list.Display();

    // Delete from head
    list.RemoveFromHead();
    cout << "After removing head: ";
    list.Display();

    // Delete from tail
    list.RemoveFromTail();
    cout << "After removing tail: ";
    list.Display();

    // Insert at position
    list.insertByPosi(99, 1);
    cout << "After inserting 99 at pos 1: ";
    list.Display();

    // Middle value
    cout << "Middle value: " << list.MiddleValue() << endl;

    // Reverse
    list.Reverse();
    cout << "Reversed List: ";
    list.Display();

    // Break into two sublists at value 3
    Node* head2 = list.breaklist(head,3);
    cout << "First Sublist: ";
    list.Display();
    cout << "Second Sublist (from 3): ";
    LinkedList l2;
    l2.head = head2;
    l2.Display();

    return 0;
}

