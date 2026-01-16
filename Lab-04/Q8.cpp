#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* prev;
		Node* next;
		Node(){
        data=0;
        prev=NULL;
        next=NULL;
    }
    	Node(int value){
        data=value;
        prev=NULL;
        next=NULL;
    }
};

class DoublyLinkedList{
	public:
		Node* head =NULL;
		Node* tail=NULL;
		
	DoublyLinkedList(){
		head=NULL;
		tail=NULL;
	}
	void insertAtEnd(int value){
		Node* newNode=new Node(value);
		if(head==NULL){
			head=tail=newNode;
		}
		else{
			tail->next=newNode;
			newNode->prev=tail;
			tail=newNode;
		}
	}
	void deleteAtFront(){
		if(head==NULL){
			cout<<"Empty list!"<<endl;
			return;
		}
		Node* temp=head;
		head=temp->next;
		if(head !=NULL){
			head->prev=NULL;
		}
		else{
			tail=NULL;
		}
		delete temp;
	}
	bool search(int value){
		Node* curr=head;
		while(curr!=NULL){
			if(curr->data==value){
				return true;
			curr=curr->next;
			}
			return false;
	}
}
void display() {
        if (head==NULL) {
            cout<<"List is empty." << endl;
            return;
        }
        Node* current=head;
        while (current!=NULL) {
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }
};
int main() {
    DoublyLinkedList d;

    d.insertAtEnd(10);
    d.insertAtEnd(20);
    d.insertAtEnd(30);
    d.insertAtEnd(50);


    cout<<"List: ";
    d.display();

    d.deleteAtFront();
    cout<<"After deleting front: ";
    d.display();

    cout<<"Search 20: "<<(d.search(20) ? "Found":"Not Found")<<endl;
    cout<<"Search 40: "<<(d.search(40) ? "Foud":"Not Found")<<endl;
    return 0;
}
