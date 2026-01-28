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
		return head;
	}
	head->left=Insert(head->left,value);
	head->right=Insert(head->right,value);
	return head;
}
void Preorder(Node* head){
	if(head==NULL){
		return;
	}
	cout<<head->data<<" ";
	Preorder(head->left);
	Preorder(head->right);
}
int main(){
	Node* root=NULL;
	
	root=Insert(root,2);
	root=Insert(root,1);
	root=Insert(root,3);
	Preorder(root);
}