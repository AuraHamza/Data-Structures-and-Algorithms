#include<iostream>
using namespace std;

class Node{
	public:
		Node* next;
		int data ;
		
		Node(int value){
			data=value;
			next=NULL;
		}
};
Node* head=NULL;
Node* tail=NULL;

void InsertByvalue(int value){
	Node* newNode=new Node(value);
	newNode->next=head;
	head=newNode;
}

void SortList(){
	if(head==NULL || head->next==NULL){
		return;
	}
	Node* i;
	Node* j;
	int temp;
	for(i=head;i!=NULL;i=i->next){
		for(j=i->next;j!=NULL;j=j->next){
			if(i->data>j->data){
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
		}
	}
}

void Display(){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}

int main(){
	InsertByvalue(40);
	InsertByvalue(80);
	InsertByvalue(90);
	InsertByvalue(10);
	InsertByvalue(20);
	InsertByvalue(50);
	cout<<"Before Sorting: "<<endl;
	Display();
	
	SortList();
	cout<<"After Sorting: "<<endl;
	Display();
}
