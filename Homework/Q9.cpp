#include<iostream>
using namespace std;
class Node{
	public:
		Node* next;
		int data;
		Node(){
			data=0;
			next=NULL;
		}
		Node(int value){
			data=value;
			next=NULL;
		}
};
void display(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
Node* deleteNode(Node* head,int val){
	if(head==NULL){
		return NULL;
	}
	head->next=deleteNode(head->next,val);
	
	if(head->data==val){
		Node* temp=head;
		head=head->next;
		delete temp;
	}
	return head;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next =new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(4);

    cout<<"Original List: ";
    display(head);

    int val=2;
    head =deleteNode(head,val);
    
    cout<<"After Deleting "<<val<<": ";
    display(head);

    return 0;
}
