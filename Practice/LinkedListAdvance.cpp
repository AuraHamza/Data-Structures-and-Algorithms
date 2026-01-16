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
class SinglyList{
	public: 
	Node* head;
	
	SinglyList() {
    head = NULL;
}

	
	void InsertAtHead(int value){
		Node* newNode=new Node(value);
		if(head==NULL){
		head=newNode;
			return;
		}
	
		newNode->next=head;
		head=newNode;
	}
	void RemoveFromvalue(int value){
		if (head == NULL) {
		return;}

		Node* temp=head;
		Node* pre=NULL;
		if(head->data==value){
			head=head->next;
			temp->next=NULL;
			delete temp;
			return;
		}
		while(temp!=NULL){
			if(temp->data==value){
				pre->next=temp->next;
				temp->next=NULL;
				delete temp;
				return;
			}
			pre=temp;
			temp=temp->next;
		}
	}

	Node* Mergelist(Node* h1,Node* h2){
		if(h1==NULL){
			return h2;
		}
			if(h2==NULL){
			return h1;
		}
		Node* head=NULL;
		if(h1->data<h2->data){
			head=h1;
			h1=h1->next;
		}else{
			head=h2;
			h2=h2->next;
		}
		Node* temp=head;
		while(h1!=NULL && h2!=NULL ){
			if(h1->data<h2->data){
				temp->next=h1;
				h1=h1->next;
			}else{
				temp->next=h2;
				h2=h2->next;
			}
			temp=temp->next;
		}
		if(h1!=NULL){
			temp->next=h1;
		}
		else if(h2!=NULL){
			temp->next=h2;
		}
		return head;
	}
	Node* SpilitList(Node* h1,int value){
    Node* temp=h1;
    Node* pre=NULL;
    while(temp!=NULL){
        if(temp->data==value){
            if(pre != NULL){
                pre->next=NULL;
            }
            return temp;
        }
        pre=temp;
        temp=temp->next;
    }
    return NULL;
}

	void Display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data;
        if(temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

};
int main() {
    SinglyList list1;

    // Insert nodes
    list1.InsertAtHead(30);
    list1.InsertAtHead(20);
    list1.InsertAtHead(10);

    cout << "List1 after inserting: ";
    list1.Display(list1.head);

    // Remove a value
    list1.RemoveFromvalue(20);
    cout << "List1 after removing value 20: ";
    list1.Display(list1.head);

    // Insert more nodes for merge example
    list1.InsertAtHead(25);
    list1.InsertAtHead(5);

    cout << "List1 before merge: ";
    list1.Display(list1.head);

    // Create second list
    SinglyList list2;
    list2.InsertAtHead(35);
    list2.InsertAtHead(15);

    cout << "List2: ";
    list2.Display(list2.head);

    // Merge lists
    Node* mergedHead = list1.Mergelist(list1.head, list2.head);
    cout << "Merged List: ";
    list1.Display(mergedHead);

    // Split merged list at value = 25
    Node* splitHead = list1.SpilitList(mergedHead, 25);
    cout << "After splitting at value 25:" << endl;

    cout << "First part: ";
    list1.Display(mergedHead);

    cout << "Second part: ";
    list1.Display(splitHead);

    return 0;
}



