#include<iostream>
#include<string>
using namespace std;
class Node{
public:
    string name;
    Node* next;

    Node(string n) {
        name=n;
        next=NULL;
    }
};
Node* head=NULL;

void addFront(string name){
	Node* temp=new Node(name);
	temp->next=head;
	head=temp;
}
void addTail(string name){
	Node* newnode=new Node(name);
	if(head==NULL){
		head=newnode;
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
}
void deleteFront(){
	if(head==NULL){
		cout<<"Queue is empty"<<endl;
		return;
	}
	Node* temp=head;
	cout<<"\nDelete "<<temp->name<<",from Front"<<endl;
	head=head->next;
	delete temp;
}

void deleteTail(){
	if(head==NULL){
		cout<<"Queue is empty "<<endl;
		return;
	}
	if(head->next==NULL){
		cout << "\nDeleted from tail:"<<head->name<<endl;
        delete head;
        head = NULL;
        return;
	}
	Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    cout <<"\nDeleted from tail: " << temp->next->name << endl;
    delete temp->next;
    temp->next = NULL;
}
void deleteAtPosition(int p) {
    if(head==NULL) {
        cout<<"Queue is empty"<<endl;
        return;
    }
    if (p==1) {
        deleteFront();
        return;
    }
    Node* temp=head;
    for (int i=1;temp!=NULL && i<p-1;i++) {
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL) {
        cout<<"Invalid position"<<endl;
        return;
    }
    Node* toDelete=temp->next;
    cout<<"\nDeleted at position "<<p<<"; "<<toDelete->name<<endl;
    temp->next = toDelete->next;
    delete toDelete;
}

void display() {
    Node* temp = head;
    cout << "\nQueue: ";
    while (temp != NULL) {
        cout << temp->name << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int main() {
	cout<<"Adding from front: "<<endl;
    addFront("Hamza");
    addFront("Noman");
    addFront("Usman");

    display();

    deleteFront();  
    display();

    addTail("Tahir");
    display();
    deleteTail();    
    display();

    deleteAtPosition(2); 
    display();
}

