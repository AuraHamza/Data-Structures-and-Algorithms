#include<iostream>
#include <climits>
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
int max_value(Node* head){
	if(head==NULL){
	 return INT_MIN;
	}
	int restmax=max_value(head->next);
	if(head->data>restmax){
		return head->data;
	}
	else{
		return restmax;
	}
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
    Node* head = new Node(3);
    head->next = new Node(7);
    head->next->next = new Node(2);
    head->next->next->next = new Node(9);

    cout << "Maximum value: " << max_value(head) << endl;

    return 0;
}

