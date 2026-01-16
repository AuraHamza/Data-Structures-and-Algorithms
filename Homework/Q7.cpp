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
Node* rotate(Node* head,int k){
	if(head==NULL || head->next==NULL || k==0){
		return head;
	}
	Node* newhead=head->next;
	Node* temp=head;
	
	Node* tail=newhead;
	while(tail->next!=NULL){
		tail=tail->next;
	}
	tail->next=head;
	head->next=NULL;
	return rotate(newhead,k-1);
}
void display(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;
    cout << "Original List: ";
    display(head);


    head = rotate(head, k);

    cout << "Rotated List by " << k << " nodes: ";
    display(head);

    return 0;
}
