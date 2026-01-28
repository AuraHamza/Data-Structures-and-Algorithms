#include<iostream>
#include<cstring>
using namespace std;

class Node{
	public:
		string name,category;
		int price;
		int height;
		Node* left;
		Node* right;
		
		Node(string n,string c,int p){
			name=n;
			category=c;
			price=p;
			height=0;
			left=NULL;
			right=NULL;
		}
};

class AVL{
	public:
		int getheight(Node* head){
			if(head==NULL){
				return -1;
			}
			return head->height;
		}
		int getBalance(Node* head){
			return getheight(head->left)-getheight(head->right);
		}
		
		//LL
		Node* RightRotate(Node* y){
			Node* x=y->left;
			Node* T2=x->right;
			
			x->right=y;
			y->left=T2;
			
			y->height=max(getheight(y->left),getheight(y->right))+1;
			x->height=max(getheight(x->left),getheight(x->right))+1;
			
			return x;
		}
		//RR
		Node* LeftRotate(Node* x){
			Node* y=x->right;
			Node* T2=y->left;
			
			y->left=x;
			x->right=T2;
			
			y->height=max(getheight(y->left),getheight(y->right))+1;
			x->height=max(getheight(x->left),getheight(x->right))+1;
			return y;
		}
		
		Node* Insert(Node* head,string name,string category,int value){
			if(head==NULL){
				return new Node(name,category,value);
			}
			
			if(value<head->price){
				head->left=Insert(head->left,name,category,value);
			}
			else if(value>head->price){
				head->right=Insert(head->right,name ,category,value);
			}
			else{
				return head;
			}
			head->height=max(getheight(head->left),getheight(head->right))+1;
			
			int balance=getBalance(head);
			
			if(balance>1){
				if(value<head->left->price){
					return RightRotate(head);
				}
				else{
					head->left=LeftRotate(head->left);
					return RightRotate(head);
				}
			}
			if(balance<-1){
				if(value>head->right->price){
					return LeftRotate(head);
				}
				else{
					head->right=RightRotate(head->right);
					return LeftRotate(head);
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
		//delete
		Node* Delete(Node* head,int value){
		
			if(head==NULL){
				return NULL;
			}
			
			if(value<head->price){
				head->left=Delete(head->left,value);
			}
			else if(value>head->price){
				head->right=Delete(head->right,value);
			}
			else{
				if((head->left==NULL)&& (head->right==NULL)){
					delete head;
					return NULL;
				}
				else if((head->left!=NULL)&& (head->right==NULL)){
					Node* temp=head->left;
					delete head;
					return temp;
				}
				else if((head->left==NULL)&& (head->right!=NULL)){
					Node* temp=head->right;
					delete head;
					return temp;
				}
				else if((head->left!=NULL)&& (head->right!=NULL)){
					Node* temp=MinValue(head->right);
					head->price=temp->price;
					head->category=temp->category;
					head->name=temp->name;
					head->right=Delete(head->right,temp->price);
					return head;
				}
			}
			if(head==NULL){
				return NULL;
			}
			head->height=max(getheight(head->left),getheight(head->right))+1;
			
			int balance=getBalance(head);
			
			if(balance>1){
				if(getBalance(head->left)>=0){
					return RightRotate(head);
				}
				else{
					head->left=LeftRotate(head->left);
					return RightRotate(head);
				}
			}
			if(balance<-1){
				if(getBalance(head->right)<0){
					return LeftRotate(head);
				}
				else{
					head->right=RightRotate(head->right);
					return LeftRotate(head);
				}
			}
			return head;		
		}
		
	void Inorder(Node* head) {
        if (head == NULL)
            return;

        Inorder(head->left);

        cout << "Name: " << head->name
            << " | Category: " << head->category
            << " | Price: " << head->price << endl;

        Inorder(head->right);
    }
};
int main(){
    AVL a;
    Node* head = NULL;

 head = a.Insert(head, "Jasmine", "Flower", 150);
head = a.Insert(head, "Sunflower", "Flower", 250);
head = a.Insert(head, "Orchid", "Flower", 1200);
head = a.Insert(head, "Marigold", "Flower", 80);
head = a.Insert(head, "Daisy", "Flower", 180);
head = a.Insert(head, "Rose", "Flower", 900);
head = a.Insert(head, "Lavender", "Flower", 600);



    cout << "\nInorder Display (Sorted by Price):\n";
    a.Inorder(head);

    head=a.Delete(head,900);
    
    cout<<"\nAfter deleting rose of 900"<<endl;
    a.Inorder(head);

    return 0;
}