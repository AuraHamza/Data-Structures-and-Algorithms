#include<iostream>
using namespace std;
class Node{
	public:
	int quantity;
	int id;
	Node* left;
	Node* right;
	Node(int q,int d){
		quantity=q;
		id=d;
		left=NULL;
		right=NULL;
	}
};
class Product{
	public: 
	Node* head;
	Node* Insert(Node* head,int q,int d){
		if(head==NULL){
			Node* newNode=new Node(q,d);
			head=newNode;
			head->left=NULL;
			head->right=NULL;
			return head;
		}
		if(d<head->id){
			head->left=Insert(head->left,q,d);
		}
		else{
			head->right=Insert(head->right,q,d);
		}
		return head;
	}
	bool Search(Node* head,int d){
		if(head==NULL){
			return false;
		}
		if(head->id==d){
			cout<<"Id: "<<head->id<<", Quantity: "<<head->quantity<<endl;
			return true;
		}

		if(d<head->id){
			Search(head->left,d);
		}
		else{
			Search(head->right,d);
		}
	}
	void Update(Node* head,int d,int q){
		if(head==NULL){
			return;
		}
		if(head->id==d){
			head->quantity=q;
			cout<<"Updated quantity: "<<q<<" , of id:"<<d<<endl;
			return;
		}
		if(d<head->id){
			Update(head->left,d,q);
		}
		else{
			Update(head->right,d,q);
		}
	}
	void Heighest(Node* head){
			if(head==NULL){
			return;
		}
		while(head->right!=NULL){
			head=head->right;
		}
			cout<<"Heighest is "<<head->id<<",Quantity:"<<head->quantity<<endl;
	}
	void Inorder(Node* head){
		if(head==NULL){
			return;
		}
		Inorder(head->left);
		cout<<"ID: "<<head->id<<"  Quantity:"<<head->quantity<<endl;
		Inorder(head->right);
	}
};
int main() {
    Product p;
    Node* head = NULL;

    head=p.Insert(head, 10, 1001);
    head=p.Insert(head, 20, 1002);
    head=p.Insert(head, 30, 1003);

    cout<<"\nInorder Traversal:" <<endl;
    p.Inorder(head);

    cout<<"\nSearch 1002:" <<endl;
    if(!p.Search(head, 1002)){
    	 cout << "Not found!" << endl;
	}

    
    p.Update(head, 1002,25);
    cout << "\nInorder Traversal:" << endl;
    p.Inorder(head);
    
    cout << "\nHighest ID Node:" << endl;
    p.Heighest(head);
}