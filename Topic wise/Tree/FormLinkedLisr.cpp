#include<iostream>
#include <vector>
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
void Inorder(Node* head,vector<int> &InorderVal){
	if(head==NULL){
		return;
	}
	Inorder(head->left,InorderVal);
	InorderVal.push_back(head->data);
	Inorder(head->right,InorderVal);
}
Node* LinkedList(Node* head){
	vector<int> InorderVal;
	Inorder(head,InorderVal);
	int i=0;
	int j=InorderVal.size();
	Node* newNode=new Node(InorderVal[i]);
	head=newNode;
	i++;
	Node* temp=head;
	
	while(i<j){
		Node* newNode=new Node(InorderVal[i]);
		temp->next=newNode;
		temp=newNode;
		i++;
	}
	return head;
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

    Node* listHead = LinkedList(root);

    cout << "Linked List (Inorder): ";
    Node* temp = listHead;
    while (temp != NULL) {
        cout << temp->data <<"->";
        temp = temp->next;
    }
    cout<<"NULL";
    cout << endl;

    return 0;
}