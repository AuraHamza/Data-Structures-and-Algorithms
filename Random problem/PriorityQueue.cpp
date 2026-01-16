#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	int priority;
	Node* next;
	
	Node(int d,int p){
		this->data=d;
		this->priority=p;
		this->next=NULL;
	}
	
	void Display(){
		cout<<" "<<priority<<" "<<data<<" ";
		cout<<endl;
	}
	
};

class PriorityQueue{
	public:
	Node* front;
	
	PriorityQueue(){
		front=NULL;
	}
	
	
	void Insert(int d, int p){
		
		Node* newnode= new Node(d,p);
		
		if(front==NULL){
			front = newnode;
			return;
		}
		
		else if(front!=NULL && p > front->priority){
			newnode->next = front;
			front = newnode;
			return;
		}
		else{
			Node* temp = front;
			
			while(temp->next!=NULL && temp->next->priority > p){
				temp=temp->next;
			}
			newnode->next=temp->next;
			temp->next= newnode;
		}
	}
	
	
	void getFirst(){
		
		if(front==NULL){
			cout<<"Queue is Empty"<<endl;
			return;
		}
		 
		 front->Display();
	}
	
	
	void Search(int data){
		
		if(front==NULL){
			cout<<"Queue is Empty"<<endl;
			return;
		}
		
		Node* temp = front;
		
		while(temp!=NULL && temp->data != data){
			temp=temp->next;
		}
		
		if(temp==NULL){
			cout<<"Not Found"<<endl;
			return;
		}
		else{
			cout<<"Found:"<<" The Priority is "<<temp->priority<<endl;
		}
		
	}
	
	
	void Delete(int data){
		
		if(front==NULL){
			cout<<"Queue is Empty"<<endl;
			return;
		}
		
		Node* curr = front;
		Node* prev=NULL;
		
		while(curr!=NULL && curr->data != data){
		   	prev=curr;
		     curr=curr->next;
		}
		
		if(curr==NULL){
			cout<<"Not Found"<<endl;
			return;
		}
		
	    else if(curr==front){
			front = front->next;
			delete curr;
		}
		
		else{
			prev->next=curr->next;
			delete curr;
			return;
	}
		
	}
	
	void RemoveFP(){
		
			if(front==NULL){
			cout<<"Queue is Empty"<<endl;
			return;
		}
		
		Node* temp=front;
		
		front=front->next;
		delete temp;
	}
	
	void Display(){
		
       Node* temp=front;
       
       while(temp!=NULL){
       	 temp->Display();
       	 temp=temp->next;
	   }
	   
	}
	
};

int main(){
	
	PriorityQueue pq;
	
	pq.Insert(30,7);
	pq.Insert(40,2);
	pq.Insert(100,4);
	pq.Insert(45,6);
	pq.Insert(50,1);
	pq.Insert(11,10);
	pq.Display();
	cout<<endl;
	pq.getFirst();
	cout<<endl;
	pq.Delete(45);
	pq.Display();
	cout<<endl;
	
	
	pq.RemoveFP();
	pq.Display();
	cout<<endl;
	
	pq.Search(100);
	
	pq.Delete(30);
	pq.Display();
	cout<<endl;
	
}