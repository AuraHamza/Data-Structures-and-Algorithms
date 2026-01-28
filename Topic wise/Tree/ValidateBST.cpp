#include<iostream>
#include <climits>
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
		head->right=Insert(head->right,data);
	}
	else{
		head->left=Insert(head->left,data);
	}
	return head;
}



bool isBST(Node* head, int min ,int max){
	if(head==NULL){
		return true;
	}
	
	if(head->data>min && head->data<max){
		bool left=isBST(head->left,min,head->data);
		bool right=isBST(head->right,head->data,max);
		return left&&right;
	}
	else{
		return false;
	}
}


bool ValidateBST(Node* head){
	return isBST(head,INT_MIN,INT_MAX);
}
int countBSTSubtrees(Node* root) {
    if (root == NULL) return 0;

    int count = 0;

    // Check if subtree rooted at current node is BST
    if (ValidateBST(root)) {
        count++;
    }

    // Recursively count in left and right subtrees
    count += countBSTSubtrees(root->left);
    count += countBSTSubtrees(root->right);

    return count;
}

int main() {
    Node* root = NULL;
    root = Insert(root, 50);
    root = Insert(root, 25);
    root = Insert(root, 7);
    root = Insert(root, 2);
    root = Insert(root, 38);
    int a =countBSTSubtrees(root);
    cout<<a;
    cout<<endl;

    if (ValidateBST(root))
        cout << "The tree is a valid BST." << endl;
    else
        cout << "The tree is NOT a valid BST." << endl;

    return 0;
}