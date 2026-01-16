#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int value){
		data=value;
		left=NULL;
		right=NULL;
    }
};

Node* Insert(Node* head,int value){
	if(head==NULL){
		Node* newNode=new Node(value);
		head=newNode;
		head->left=NULL;
		head->right=NULL;
		return head ;
	}
	if(value<head->data){
		head->left=Insert(head->left,value);
	}
	else{
	head->right=Insert(head->right,value);
	}
	return head;
}
void Inorder_Travesel(Node* head){//LNR 
	if(head==NULL){
		return ;
	}
	Inorder_Travesel(head->left);
	cout<<head->data<<" ";
	Inorder_Travesel(head->right);
}
void PreOrder_Travesel(Node* head){//NLR
	if(head==NULL){
		return;
	}
	cout<<head->data<<" ";
	PreOrder_Travesel(head->left);
	PreOrder_Travesel(head->right);
}
void PostOrder_Travesel(Node* head){
		if(head==NULL){

		return;
	}
	
	PostOrder_Travesel(head->left);
	PostOrder_Travesel(head->right);
	cout<<head->data<<" ";
}
int main(){
	
	Node* head=NULL;
	head=Insert(head,1);
	head=Insert(head,100);
	head=Insert(head,55);
	head=Insert(head,10);
	head=Insert(head,99);
	head=Insert(head,54);
	head=Insert(head,82);
	cout<<"InOrder: ";
	Inorder_Travesel(head);
	cout<<endl;
	cout<<"Pre-Order: ";
	PreOrder_Travesel(head);
	cout<<endl;
	cout<<"Post-Order: ";
	PostOrder_Travesel(head);
	
}