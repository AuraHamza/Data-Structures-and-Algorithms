#include<iostream>
#include<queue>
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
Node* head=NULL;
void BST_Insert(int value){
	Node* newNode=new Node(value);
	if(head==NULL){
		head=newNode;
		return ;
	}
	else{
		Node* temp=head;
		while(temp!=NULL){
			if(newNode->data==temp->data){
				cout<<"No duplicates allowed";
				return;
			}
			else if((newNode->data<temp->data)&& (temp->left==NULL)){
				temp->left=newNode;
				break;
			}
			else if(newNode->data<temp->data){
				temp=temp->left;
			}
			else if((newNode->data>temp->data)&& (temp->right==NULL)){
				temp->right=newNode;
				break;
			}
			else{
				temp=temp->right;
			}
		}
	}
}
Node* CompleteTree(Node* head,int value){
	Node* newNode=new Node(value);
	if(head==NULL){
		head=newNode;
		return head;
	}
	queue<Node*> q;
	q.push(head);
	while(!q.empty()){
		Node* temp=q.front();
		q.pop();
		if(temp->left==NULL){
			temp->left=newNode;
			break;
		}else{
			q.push(temp->left);
		}
		if(temp->right==NULL){
			temp->right=newNode;
			break;
		}else{
			q.push(temp->right);
		}
	}
	return head;
}
void LevelOrder(Node* head){
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
int main() {
    cout << "BST Insertion:\n";
    BST_Insert(10);
    BST_Insert(5);
    BST_Insert(15);
    BST_Insert(3);
    BST_Insert(7);
    cout << "BST (Level Order): ";
    LevelOrder(head);
   
    cout <<"\n\nComplete Binary Tree Insertion:\n";
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "
	Before insertion: ";
    LevelOrder(root);
    root = CompleteTree(root, 6);
    cout << "\nAfter insertion: ";
    LevelOrder(root);

    return 0;
}
