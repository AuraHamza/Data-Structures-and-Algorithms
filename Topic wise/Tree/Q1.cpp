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
bool Search(Node* head ,int x){
	if(head==NULL){
		return false;
	}
	if(head->data==x){
		return true;
	}
	if(x>head->data){
		return Search(head->right,x);
	}else{
		return Search(head->left,x);
	}
}

Node* MinValue(Node* head){
	Node* temp=head;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}
Node* MaxValue(Node* head){
	Node* temp=head;
	while(temp->right!=NULL){
		temp=temp->right;
	}
	return temp;
}
//Enter dena baqi ha 
//void LevelOrderTravesal(Node* head){
//	queue<Node*>q;
//	q.push(head);
//	q.push(NULL);
//	
//	while(!q.empty){
//		Node* temp=q.front();
//		q.pop();
//		if(temp->left){
//			q.push(temp->left);
//		}
//		if(temp->right){
//			q.push(temp->right);
//		}
//		
//	}
//}
void InOrder(Node* head){//LNR
	if(head==NULL){
		return;
	}
	InOrder(head->left);
	cout<<head->data<<" ";
	InOrder(head->right);
}
void PreOrder(Node* head){//NLR
	if(head==NULL){
		return;
	}
	cout<<head->data<<" ";
	PreOrder(head->left);
	PreOrder(head->right);
}
void PostOrder(Node* head){//LRN
	if(head==NULL){
		return;
	}
	PostOrder(head->left);
	PostOrder(head->right);
	cout<<head->data<<" ";
}
Node* Predecessor(Node* head,Node* key){
	if(head==NULL){
		return NULL;
	}
	Node* after=NULL;
	Node* temp=head;
	while(temp!=NULL){
		if(key->data>temp->data){
			after=temp;
			temp=temp->right;
		}
		else{
			temp=temp->left;
		}
	}
	return after;
}
Node* Successor(Node* head,Node* key){
	if(head==NULL){
		return NULL;
	}
	Node* before=head;
	Node* temp=head;
	while(temp!=NULL){
			if(key->data<temp->data){
		before=temp;
		temp=temp->left;
	}
	else{
		temp=temp->right;
	}
}
	return before;	
}
Node* DeleteFromBST(Node* head,int value){
	if(head==NULL){
		return NULL;
	}
	if(head->data==value){
		//0 child
		if((head->left==NULL)&&(head->right==NULL)){
			delete head;
			return NULL;
		}
		//1 child
		//left child
		if((head->left!=NULL)&&(head->right==NULL)){
			Node* temp=head->left;
			delete head;
			return temp;
		}
		//right child
		if((head->left==NULL)&&(head->right!=NULL)){
			Node* temp=head->right;
			delete head;
			return temp;
		}
		//2 child
		if((head->left!=NULL)&&(head->right!=NULL)){
			int min=MinValue(head->right)->data;//right ka min value
			head->data=min;
			head->right=DeleteFromBST(head->right,min);
			return head;
		}
		
	}
	else if(head->data>value){
		head->left=DeleteFromBST(head->left,value);
		return head;
	}
	else if(head->data<value){
		head->right=DeleteFromBST(head->right,value);
		return head;
	}
}
// Main function
int main() {
    Node* root = NULL;

    // Inserting nodes
    root = Insert(root, 8);
    root = Insert(root, 3);
    root = Insert(root, 10);
    root = Insert(root, 1);
    root = Insert(root, 6);
    root = Insert(root, 14);
    root = Insert(root, 4);
    root = Insert(root, 7);
    root = Insert(root, 13);

//    cout << "Level Order Traversal:\n";
//    LevelOrderTraversal(root);

    cout << "\n\nInorder Traversal: ";
    InOrder(root);
    cout << "\nPreorder Traversal: ";
    PreOrder(root);
    cout << "\nPostorder Traversal: ";
    PostOrder(root);

    cout << "\n\nSearching 7: " << (Search(root, 7) ? "Found" : "Not Found");
    cout << "\nMinimum Value: " << MinValue(root)->data;
    cout << "\nMaximum Value: " << MaxValue(root)->data;
    Node* key = root->right->left;  // key = 60
    Node* ans = Successor(root, key);
    cout<<"\nSuccessor: "<<ans->data;
    Node* p =Predecessor(root,key);
    cout<<"\nPredecessor: "<<p->data;
    DeleteFromBST(root,3);
    cout << "\n\nInorder Traversal: ";
    InOrder(root);
    

    return 0;
}