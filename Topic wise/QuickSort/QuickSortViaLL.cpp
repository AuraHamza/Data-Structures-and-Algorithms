#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int value){
			data=value;
			next=NULL;
		}
};

class SinglyLinkedList{
	public:
		Node* head;
		Node* tail;
		SinglyLinkedList(){
			head=NULL;
			tail=NULL;
		}
		void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
	 void swap(Node* h1, Node* h2) {
        int temp = h1->data;
        h1->data = h2->data;
        h2->data = temp;
    }


	void QuickSort(Node* head,Node* tail){
		if(!head||!tail||head==tail){
			return ;
		}
	Node* pivot=partition(head,tail);
	Node* temp=head;
	Node* pre=NULL;
	while(temp!=pivot){
		pre=temp;
		temp=temp->next;
	}
	if(pre){QuickSort(head,pre);}
    if(pivot!=NULL && pivot->next!=NULL){QuickSort(pivot->next,tail);}
    }
    
    Node* partition(Node* head,Node* tail){
    	int pivot=tail->data;
    	Node* i=head;
    	Node* j=head;
    	while(j!=tail){
    		if(j->data<pivot){
    			swap(i,j);
    			i=i->next;
			}
			j=j->next;
		}
		swap(i,tail);
		return i;
	}
	
	 void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};
int main() {
    SinglyLinkedList list;
    list.insert(10);
    list.insert(7);
    list.insert(8);
    list.insert(9);
    list.insert(1);
    list.insert(5);
    list.insert(3);
    cout << "Original list: ";
    list.print();

    list.QuickSort(list.head, list.tail);

    cout << "Sorted list: ";
    list.print();
}