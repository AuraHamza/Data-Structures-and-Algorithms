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

void inorder(Node* root,int arr[],int &n){
	if(root!=NULL){
		inorder(root->left,arr,n);
		arr[n++]=root->data;
	inorder(root->right,arr,n);		
	}
}

void preOrder(Node* root,int arr[],int &n){
	if(root!=NULL){
		root->data=arr[n++];
		preOrder(root->left,arr,n);
		preOrder(root->right,arr,n);
	}
}
void printHeap(Node* root) {
    if(!root) return;
    cout << root->data << " ";
    printHeap(root->left);
    printHeap(root->right);
}
int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    int n = 7;            // number of nodes
    int arr[n];           // array to store inorder elements
    int index = 0;

    inorder(root, arr, index);

    index = 0; 
    preOrder(root, arr, index);

    cout << "Min Heap (level order): ";
    printHeap(root);
    cout << endl;

    return 0;
}