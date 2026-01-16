#include<iostream>
#include<cstring>
using namespace std;
class Node{
	public:
	string name;
	Node* next;
	
	Node(){
		this->name="";
		this->next=NULL;
	}
	Node(string name){
		this->name=name;
		this->next=NULL;
	}	
};
Node* head=NULL;
Node* tail=NULL;

void AddFromFront(string name){
	Node* n=new Node(name);
	n->next=head;
	head=n;
cout<<name<<" ,Added from Front"<<endl;
}

void AddFromEnd(string name){
	Node* n=new Node(name);
	if(head==NULL){
		head=n;
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
}
temp->next=n;
cout<<name<<" ,Added from End"<<endl;
}

void DeleteByValue(string name){
	if(head==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	Node* curr=head;
	Node* pre;
	if(head->name==name){
		curr=head;
		head=head->next;
		delete curr;
		cout<<"Deleted: "<<name<<endl;
		return;
	}
	while(curr->next!=NULL && curr->name!=name){
		pre=curr;
		curr=curr->next;
	}
	if (curr==NULL){
        cout<<"Value not found"<<endl;
        return;
    }
	pre->next=curr->next;
	delete curr;
	cout<<"Deleted: "<<name<<endl;

}
void DeleteFromFront(){
	if(head==NULL){
		cout<<"Nothing in the list(From front function)"<<endl;
		return;
	}
	Node* temp=head;
	cout<<"Deleted: "<<temp->name<<endl;
	head=head->next;
	delete temp;
}
void DeleteFromEnd(){
	    if (head==NULL) {
        cout<<"Nothing in the list (from end function)" << endl;
        return;
    }
    if (head->next==NULL) { 
        delete head;
        head=NULL;
        return;
    }

	Node* temp=head;
	Node* pre;
	if(head==NULL){
		cout<<"Nothing in the list(from end function)";
	}
	while(temp->next!=NULL){
		pre=temp;
		temp=temp->next;
	}
	tail=pre;
	cout<<"Deleted: "<<temp->name<<endl;
	tail->next=NULL;
	delete temp;
}
void Display() {
	 if (head==NULL){
        cout<<"Linked List is empty." << endl;
        return;
    }
    Node* temp=head;   

    cout<<"Linked List: ";
    while(temp!=NULL) {       
        cout<<temp->name<<"->";
        temp=temp->next;       
    }
    cout<<"NULL"<<endl;     
}


int main(){
AddFromFront("Hamza");
AddFromEnd("Ibrahim");
AddFromFront("Yasir");
AddFromFront("Tahir");
AddFromEnd("Taha");
AddFromFront("Saad");
AddFromEnd("Don");

Display();

DeleteByValue("Taha");
DeleteFromFront();
DeleteFromEnd();

Display();

}
