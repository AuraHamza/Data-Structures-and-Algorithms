#include<iostream>
using namespace std;

class Node{
	public:
		Node* next;
		int data;
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
void InsertByvalue(int value){

	Node* newNode=new Node(value);
	newNode->next=head;
	head=newNode;
}

Node* deleteDup(Node* head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	head->next=deleteDup(head->next);
	if(head->data==head->next->data){
		Node* temp=head->next;
		delete head;
		return temp;
	}
	return head;
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

    InsertByvalue(50);
	InsertByvalue(40);
	InsertByvalue(30);
	InsertByvalue(30);
	InsertByvalue(20);
	InsertByvalue(10);
	
	cout << "Original List: "<<endl;
	display();
	
	head=deleteDup(head);
	
	    cout << "After Removing Duplicates: "<<endl;
		display();
		return 0;
	
}
