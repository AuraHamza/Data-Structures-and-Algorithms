#include<iostream>]
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

bool compareList(Node* head1,Node* head2){
	if(head1==NULL && head2==NULL){
		return true;
	}
	if(head1==NULL || head2==NULL){
		return false;
	}
	if(head1->data != head2->data){
		return false;
	}
	return  compareList(head1->next,head2->next);
}
int main() {
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    if (compareList(head1, head2)){
	  cout<<"Lists are equal"<<endl;
    }
    else{
        cout<<"Lists are not equal"<<endl;
    }
    head2->next->next->data=4;
    cout<<"After adding 4 in list 2!"<<endl;

    if (compareList(head1,head2)){
	cout<<"Lists are equal"<<endl;}
    else{
        cout<<"Lists are not equal"<<endl;
		}
    return 0;
}

