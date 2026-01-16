#include<iostream>
#include<stack>
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
	if(data<head->data){
		head->left=Insert(head->left,data);
	}else{
		head->right=Insert(head->right,data);
	}
	return head;
}

void Travse(Node* head){
	if(head==NULL){
		return;
	}
	stack <Node*> s;
	s.push(head);
	
	while(!s.empty()){
		Node* temp=s.top();
		s.pop();
		cout<<temp->data<<" ";
		
		if(temp->right){
			s.push(temp->right);
		}
		if(temp->left){
			s.push(temp->left);
		}
		
	}
}
int main(){
	Node* head=NULL;
	head=Insert(head,50);
	head=Insert(head,30);
	head=Insert(head,20);
	head=Insert(head,40);
	head=Insert(head,70);
	head=Insert(head,60);
	head=Insert(head,80);

	

	
	Travse(head);
}