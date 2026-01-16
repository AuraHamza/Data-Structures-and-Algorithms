#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* mergeSortedLists(Node* a, Node* b) {
    if (!a){
	 return b;}
    if (!b){
	 return a;}

    if (a->data<b->data) {
        a->next = mergeSortedLists(a->next, b);
        return a;
    } else {
        b->next = mergeSortedLists(a, b->next);
        return b;
    }
}

void splitList(Node* head, Node** firstHalf, Node** secondHalf) {
    if (!head || !head->next) {
        *firstHalf = head;
        *secondHalf = NULL;
        return;
    }

    Node* slow=head;
    Node* fast=head->next;

    while (fast&&fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *firstHalf=head;
    *secondHalf=slow->next;
    slow->next=NULL;
}

Node* sortLinkedList(Node* head) {
    if (!head || !head->next){
    	 return head;
	}

    Node* firstHalf;
    Node* secondHalf;

    splitList(head, &firstHalf, &secondHalf);

    firstHalf=sortLinkedList(firstHalf);
    secondHalf=sortLinkedList(secondHalf);

    return mergeSortedLists(firstHalf, secondHalf);
}

bool isSorted(Node* head) {
    while (head && head->next) {
        if (head->data>head->next->data) {
        	return false;
		}
        head = head->next;
    }
    return true;
}

void printList(Node* head) {
    while (head) {
        cout<<head->data << "->";
        head=head->next;
    }
    cout<<endl;
}

int main() {
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(3);

    cout<<"Original List: ";
    printList(head);

    head=sortLinkedList(head);

    cout<<"Sorted List: ";
    printList(head);

    if(isSorted(head))
        cout<<"The list is sorted."<<endl;
    else
        cout<<"The list is NOT sorted."<<endl;
    return 0;
}

