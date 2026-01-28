#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	int height;
	Node* left;
	Node* right;
	Node(int value){
		data=value;
		left=NULL;
		right=NULL;
		height=0;
	}
};

int Heightcheck(Node* head){
	if(head==NULL){
		return 0;
	}
	if(head->left != NULL && head->data > head->left->data)
        return 0;

    if(head->right != NULL && head->data > head->right->data){
    	return 0;
        
	}
	
        
		int left=Heightcheck(head->left);
		int right=Heightcheck(head->right);
		    return 1 + min(left, right);

}