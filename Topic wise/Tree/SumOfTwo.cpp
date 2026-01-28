#include<iostream>
#include <vector>
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
void Inorder(Node* head,vector<int> &inorderVal){
	if(head==NULL){
		return;
	}
	Inorder(head->left,inorderVal);
	inorderVal.push_back(head->data);
	Inorder(head->right,inorderVal);
}

bool SumofTwo(Node* head,int target){
	vector<int> inorderVal;
	Inorder(head,inorderVal);
	int i=0; int j=inorderVal.size()-1;
	while(i<j){
		int sum=inorderVal[i]+inorderVal[j];
		if(sum==target){
			return true;
		}
		else if(sum>target){
			j--;
		}
		else{
			i++;
		}
	}
	return false;
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

    int target = 10;

    if (SumofTwo(root, target))
        cout << "Pair with sum " << target << " exists.\n";
    else
        cout << "No pair found with sum " << target << ".\n";

    return 0;
}
