#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data=value;
        next=NULL;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head=NULL;
    }

    void insertAtEnd(int value) {
        Node* newNode=new Node(value);

        if (head==NULL) {
            head=newNode;
        } else {
            Node* temp=head;
            while(temp->next!=NULL) {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }

    void display() {
        if (head==NULL) {
            cout<<"List is empty."<<endl;
            return;
        }
        Node* temp=head;
        cout<<"Linked List: ";
        while (temp!=NULL) {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    bool Ispalandrome() {
    	Node* slow=head;
    	Node* fast=head;
    	while(fast->next!=NULL && fast->next->next!=NULL){
    		fast=fast->next->next;
    		slow=slow->next;
		}
		Node* curr=slow->next;
		Node* prev=NULL;
		Node* newNode=NULL;
		while(curr!=NULL){
			newNode=curr->next;
			curr->next=prev;
			prev=curr;
			curr=newNode;
		}
		Node* h=head;
		Node* rev=prev;
		while(rev!=NULL){
			if(h->data!=rev->data){
				return false;
			}
			h=h->next;
			rev=rev->next;
		}
    	return true;
}

};

int main() {
    SinglyLinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(2);
    list.insertAtEnd(1);

    list.display();
    
    if (list.Ispalandrome()) {
    cout << "Yes, it is a Palindrome." << endl;
} else {
    cout << "No, it is not a Palindrome." << endl;
}

    return 0;
}

