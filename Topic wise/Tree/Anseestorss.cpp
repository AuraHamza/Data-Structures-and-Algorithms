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

Node* Insert(Node* head,int data){
	if(head==NULL){
		Node* newNode=new Node(data);
		head=newNode;
		head->left=NULL;
		head->right=NULL;
		return head;
	}
	if(data>head->data){
		//right node
		head->right=Insert(head->right,data);
	}
	else{
		head->left=Insert(head->left,data);
	}
	return head;
}

Node* Ancesstor(Node* head,int p,int q){
	Node* curr=head;
	if(p<head->data && q<head->data){
		head->left=Ancesstor(head->left,p,q);
	}
	else if(p>head->data && q>head->data){
		head->right=Ancesstor(head->right,p,q);
	}
	else{
		return head;
	}
}
int main(){
	Node* head=NULL;
	
	head=Insert(head,56);
	head=Insert(head,17);
	head=Insert(head,82);
	head=Insert(head,70);
	head=Insert(head,4);
	head=Insert(head,37);
	
	cout<<"Ancesstor: ";
	
	head=Ancesstor(head,4,37);
	cout<<head->data;
}