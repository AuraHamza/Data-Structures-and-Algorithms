#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		Node* next;
		
	Node(int value){
		data=value;
		left=NULL;
		right=NULL;
		next=NULL;
	}
};
Node* MinValue(Node* head){
	Node* temp=head;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}

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
Node* DeleteNode(Node* head,int key){
	if(head==NULL){
		return NULL;
	}
	if(head->data==key){
		if((head->left==NULL)&& (head->right==NULL)){
			delete head;
			return NULL;
		}
		//if one child
		//if left child
		if((head->left!=NULL)&& (head->right==NULL)){
			Node* temp=head->left;
			delete head;
			return temp;
		}
		//if right child
		if((head->left==NULL)&& (head->right!=NULL)){
			Node* temp=head->right;
			delete head;
			return temp;
		}
		//2 child
		if((head->left!=NULL)&& (head->right!=NULL)){
			int min=MinValue(head->right)->data;
			//copy data/value
			head->data=min;
			head->right=DeleteNode(head->right,min);
			return head;
		}
	}
	else if(key<head->data){
		head->left=DeleteNode(head->left,key);
		return head;
	}
	else{
		head->right=DeleteNode(head->right,key);
		return head;
	}
}
// Inorder traversal for testing
void InOrder(Node* head) {
	if (head == NULL) return;
	InOrder(head->left);
	cout << head->data << " ";
	InOrder(head->right);
}

int main() {
	Node* root = NULL;
	root = Insert(root, 5);
	root = Insert(root, 3);
	root = Insert(root, 7);
	root = Insert(root, 2);
	root = Insert(root, 4);
	root = Insert(root, 6);
	root = Insert(root, 8);

	cout << "Before deletion (Inorder): ";
	InOrder(root);
	cout << endl;

	root = DeleteNode(root, 7);

	cout << "After deleting 7 (Inorder): ";
	InOrder(root);
	cout << endl;
}