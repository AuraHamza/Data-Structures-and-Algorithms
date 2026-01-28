#include<iostream>
#include<cstring>
using namespace std;

class Node{
	public:
		int id;
		string desp;
		Node* left; 
		Node* right;
		
		Node(string d,int id){
			desp=d;
			id=id;
			left=NULL;
			right=NULL;
		}
};

class WMS{
	public:
		Node* insert(Node* head,string d,int i){
			if(head==NULL){
				return new Node(d,i);
			}
			if(i<head->id){
			head->left=insert(head->left,d,i);	
			}
			else if(i>head->id){
				head->right=insert(head->right,d,i);
			}
				return head;
			
		}
		
		Node* Minvalue(Node* head){
			Node* temp=head;
			while(temp->left!=NULL){
				temp=temp->left;
			}
			return temp;
			
		}
		Node* Delete(Node* head,int i){
				if(head==NULL){
				return NULL;
			}
			if(i<head->id){
			head->left=Delete(head->left,i);	
			}
			else if(i>head->id){
				head->right=Delete(head->right,i);
			}else{
				if((head->left==NULL)&& (head->right==NULL)){
					delete head;
					return NULL;
				}
				else if((head->left!=NULL)&& (head->right==NULL)){
					Node* temp= head->left;
					delete head;
					return temp;
				}
				else if((head->left==NULL)&& (head->right!=NULL)){
					Node* temp=head->right;
					delete head;
					return temp;
				}
				else{
					Node* temp=Minvalue(head->right);
					head->desp=temp->desp;
					head->id=temp->id;
					head->right=Delete(head->right,temp->id);
					return head;
			    }	
			}
		}
		 void Kprint(Node* head, int low , int high){
            if(head == NULL) return;

            if(low <= head->id && head->id <= high){
                cout << "ID: " << head->id << " || Description: " << head->desp << endl;
            }
            if(low < head->id) Kprint(head->left, low , high);
            if(high > head->id) Kprint(head->right, low , high);
        }
};
int main(){
	 WMS wms;
    Node* root = NULL;

    // Insert some nodes
    root = wms.insert(root,"Item A", 10);
    root = wms.insert(root,"Item B", 5);
    root = wms.insert(root,"Item C", 15);
    root = wms.insert(root,"Item D", 12);

    cout<<"All items between ID 5 and 15:\n";
    wms.Kprint(root,5,15);
}
