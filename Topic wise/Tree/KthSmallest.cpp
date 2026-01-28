#include<iostream>
#include<vector>
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

void Inorder(Node* head,vector<int>&inorderVAL){
	if(head==NULL){
		return ;
	}
	Inorder(head->left,inorderVAL);
	inorderVAL.push_back(head->data);
	Inorder(head->right,inorderVAL);
}
int KthSmallest(Node* head,int k ){
	vector<int>inorderVAL;
	Inorder(head,inorderVAL);
	int m=0;
	for(int i=0;i<k;i++){
		m=inorderVAL[i];
	}
	return m;
}
int main() {
    Node* root = NULL;
    root = Insert(root, 5);
    root = Insert(root, 34);
    root = Insert(root, 12);
    root = Insert(root, 43);
    root = Insert(root, 53);
    root = Insert(root, 61);
    root = Insert(root, 82);

    int n=KthSmallest(root,3);
    cout<<"Kth smallest is:"<<n;

    return 0;
}