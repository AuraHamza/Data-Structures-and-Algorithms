#include<iostream>
#include<cstring>
using namespace std;

class Node{
	public:
		string title;
		Node* next;
		Node(string title){
			this->title=title;
			this->next=NULL;
		}
};
Node* head=NULL;

void addSong(string title){
	Node* n=new Node(title);
	if(head==NULL){
		head=n;
	}else{
	 Node* temp=head;
	 while(temp->next!=NULL){
	 	temp=temp->next;
	 }
	 temp->next=n;
	}
	 cout<<title<<",Add at tail"<<endl;

}

void deleteFront(){
	if(head==NULL){
		cout<<"Playlist in empty"<<endl;
		return;
	}
	Node* temp=head;
	cout<<"\nDeleted songs: "<<temp->title<<endl;
	head=head->next;
	delete temp;
}

void searchByTitle(string title){
	Node* temp =head;
	while(temp!=NULL){
		if(temp->title==title){
			cout<<"\nSong"<<title<<",found by tittle "<<endl;
			return;
		}
		temp=temp->next;
	} 
	cout<<"Song"<<title<<",notfound "<<endl;

}
void searchByPosition(int p){
	Node* temp=head;
	int count=1;
	while(temp!=NULL){
		if(count==p){
	    cout<<"\nSong"<<temp->title<<",at position:"<<p<<endl;
        return;
		}
		 temp = temp->next;
        count++;
	}
	cout<<"Song not found at this position"<<endl;
}
void display(){
	if(head==NULL){
		cout<<"\nPlaylist is empty"<<endl;
		return;
	}
	Node* temp=head;
	cout<<"\nPlaylist:"<<endl;
	while(temp!=NULL){
		cout<<temp->title<<endl;
		temp=temp->next;
	}
}
int main(){
	addSong("Song1");
    addSong("Song2");
    addSong("Song3");
    display();
    deleteFront();
    cout<<"\nAfter front delete"<<endl;
    display();
   searchByTitle("Song2");
    searchByPosition(2);
    return 0;
}
