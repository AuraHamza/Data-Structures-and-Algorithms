#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		int height;
		Node(int value){
			data=value;
			left=NULL;
			right=NULL;
			height=0;
		}
		
};
int getheight(Node* head){
	if(head==NULL){
		return -1;
	}
	return head->height;
}
int getBalance(Node* head){
	if(head==NULL){
		return 0;
	}
	return getheight(head->left)-getheight(head->right);
}
//Right Rotation
Node* RightRotation(Node* y){
	Node* x =y->left;
	Node* T2=x->right;
	
	x->right=y;
	y->left=T2;
	
	y->height=max(getheight(y->left),getheight(y->right))+1;
	x->height=max(getheight(x->left),getheight(x->right))+1;
	
	return x;
}

//Left Rotation
Node* LeftRotation(Node* x){
	Node* y=x->right;
	Node* T2=y->left;
	
	y->left=x;
	x->right=T2;

	x->height=max(getheight(x->left),getheight(x->right))+1;	
	y->height=max(getheight(y->left),getheight(y->right))+1;
	
	return y;
}

Node* insert(Node* head,int key){
	if(head==NULL){
		return new Node(key);
	}
	
	if(key<head->data){
		head->left=insert(head->left,key);
	}
	else if(key>head->data){
		head->right=insert(head->right,key);
	}
	else{
		return head;
	}
	//height of head
	head->height=max(getheight(head->left),getheight(head->right))+1;
	
	//check balance;	
	int balance=getBalance(head);
	
	
	//LL case
	if(balance>1){
		if(key<head->left->data){
		return RightRotation(head);
	}
	//LR
	if(key>head->left->data){
		head->left=LeftRotation(head->left);
		return RightRotation(head);
	}
}
	
	
	//RR case
	if(balance<-1){
		if(key>head->right->data){
		return LeftRotation(head);
	}
	//RL
	if(key<head->right->data ){
		head->right=RightRotation(head->right);
		return LeftRotation(head);
	}
		}
	
	return head;
}

Node* MinValue(Node* head){
	Node* temp=head;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}


Node* Delete(Node* head, int key) {
	if(head==NULL){
		return NULL;
	}
	
	//if there value found
	if(head->data==key){
	
		//No child
		if((head->left==NULL)&& (head->right==NULL)){
			delete head;
			return NULL;
		}
		//Left child
		else if((head->left!=NULL)&& (head->right==NULL)){
			Node* temp=head->left;
			delete head;
			return temp;
		}
		//Right child
		else if((head->left==NULL)&& (head->right!=NULL)){
			Node* temp=head->right;
			delete head;
			return temp;
		}
		//two child
		else if((head->left!=NULL)&& (head->right!=NULL)){
			int min=MinValue(head->right)->data;
			head->data=min;
			head->right=Delete(head->right,min);
			return head;
		}
	}
	else if(key<head->data){
		head->left=Delete(head->left,key);
		return head;
	}
	else if(key>head->data){
		head->right=Delete(head->right,key);
		return head;
	}
	
	if(head==NULL){
		return head;
	}
	head->height=max(getheight(head->left),getheight(head->right))+1;
	
	int balance=getBalance(head);
	
	if(balance>1){
		if(getBalance(head->left)>=0){
			return RightRotation(head);
		}
		else{
			head->left=LeftRotation(head->left);
			return RightRotation(head);
		}
	}
	else if(balance<-1){
		if(getBalance(head->right)<0){
			return LeftRotation(head);
		}
		else{
			head->right=RightRotation(head->right);
			return LeftRotation(head);
		}
	}
	return head;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << "(" << root->height << ") ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder traversal with heights (leaf=0): ";
    inorder(root);
    cout << endl;
    
     root = Delete(root, 40);

    cout << "Inorder after deleting 40: ";
    inorder(root);
    cout << endl;

    return 0;
}