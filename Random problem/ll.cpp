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

    void EvenOddCheck() {
    Node* evenh=NULL;
    Node* eventail=NULL;
    Node* oddh=NULL;
    Node* oddtail=NULL;
    Node* curr=head;
    while(curr!=NULL){
    	if(curr->data%2==0){
    		if(evenh==NULL){
    			eventail=curr;
    			evenh=curr;
			}
			else{
				eventail->next=curr;
				eventail=curr;
			}	
		}
		else{
			if(oddh==NULL){
    			oddh=curr;
    			oddtail=curr;
			}
			else{
				oddtail->next=curr;
				oddtail=curr;
			}
		}
		curr=curr->next;
	}
	if(oddtail!=NULL){
		oddtail->next=NULL;	
		}
		if(eventail!=NULL){
		eventail->next=oddh;
	}
	
}


void concatenate(SinglyLinkedList &other) {
    if (head==NULL){
    	head=other.head;
    	return;
	} 
    Node* temp=head;
    while(temp->next!=NULL){
    	  temp = temp->next;
	}
	    temp->next=other.head;
    return;
}

};

int main() {
    SinglyLinkedList list1, list2;
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);
    list1.insertAtEnd(4);
    list1.display();

    list2.insertAtEnd(6);
    list2.insertAtEnd(7);
    list2.insertAtEnd(8);
    list2.display();

    list1.EvenOddCheck();
    list2.EvenOddCheck();

    cout << "List 1 after Even-Odd rearrange: ";
    list1.display();

    cout << "List 2 after Even-Odd rearrange: ";
    list2.display();

    list1.concatenate(list2);

    cout << "Final combined Even-Odd list: ";
    list1.display();

    return 0;
}

