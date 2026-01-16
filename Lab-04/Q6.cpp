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
Node* head=NULL;
Node* tail=NULL;

void Insert(int value){
	Node* newNode=new Node(value);
	newNode->next=head;
	head=newNode;
}

Node* MergeSortedLists(Node* L1,Node* L2){
	if(L1==NULL){return L2 ;}
		if(L2==NULL){return L2;}
	if(L1->data<=L2->data){
		L1->next=MergeSortedLists(L1->next,L2);
		return L1;
	}
	else{
		L2->next=MergeSortedLists(L1,L2->next);
		return L2;	
	}
}
void Display(Node* head){
	Node* temp=head;
	do{
		cout<<"Task:"<<temp->data<<"->";
		temp=temp->next;
	}while(temp!=NULL);
	cout<<"NULL"<<endl;
}
int main() {
    Node* L1 = new Node(1);
    L1->next = new Node(3);
    L1->next->next = new Node(5);

    Node* L2 = new Node(2);
    L2->next = new Node(4);
    L2->next->next = new Node(6);

    cout<<"List 1: ";
    Display(L1);

    cout<<"List 2: ";
    Display(L2);

    Node* mergedList=MergeSortedLists(L1, L2);

    cout<<"Merged Sorted List (Recursion): ";
    Display(mergedList);
}

