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

    bool hasCycle() {
    Node* fast=head;
    Node* slow=head;

    while (fast != NULL && fast->next != NULL) {
        fast=fast->next->next; 
        slow=slow->next;       
        if (fast==slow) {      
            return true;
        }
    }
    return false; 
}

};

int main() {
    SinglyLinkedList list;

    cout <<"Inserting elements"<<endl;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    if (list.hasCycle()) {
        cout<<"Yes, the linked list has a cycle."<<endl;
    } else {
        cout<<"No, the linked list does not have a cycle."<<endl;
    }

    return 0;
}

