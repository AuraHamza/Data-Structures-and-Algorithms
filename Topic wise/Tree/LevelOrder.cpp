#include<iostream>
#include<queue>
#include<Stack>
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
void LevelOrder(Node* head){
	if(head==NULL){
		return;
	}
	queue<Node*> q;
	q.push(head);
	
	while(!q.empty()){
		Node* temp=q.front();
		q.pop();
		
		cout<<temp->data<<" ";
		if(temp->left){
			q.push(temp->left);
		}
		if(temp->right){
			q.push(temp->right);
		}
	}
}


int main(){
	Node* head=NULL;
	head=Insert(head,8);
	head=Insert(head,3);
	
	head=Insert(head,10);
	head=Insert(head,1);
	head=Insert(head,6);
	head=Insert(head,14);
	head=Insert(head,4);
	head=Insert(head,7);
	head=Insert(head,13);

	LevelOrder(head);
	
}