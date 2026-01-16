#include<iostream>
#include<cstring>
using namespace std;

class Playlist{
	int front,rear,capacity;
	string song[5];
	public:
		Playlist(){
		front =-1;
		rear=-1;
		capacity=5;
		}
	bool isEmpty(){
		return(front==-1 && rear==-1);
	}
	bool isFull(){
		return((rear+1)%capacity==front);
	}
	void addSongs(string s){
		if(isFull()){
			cout<<"Playlist is Full"<<endl;
			return;
		}
		if(isEmpty()){
			rear=front=0;
			song[rear]=s;
			return;
		}
		rear=(rear+1)%capacity;
		song[rear]=s;
	}
	void PlayNext(){
		if(isEmpty()){
			cout<<"Playlist is Empty";
			return;
		}
		front=(front+1)%capacity;
		cout<<"Playing Next:"<<song[front]<<endl;
	}
	
	void display(){
		if(isEmpty()){
			cout<<"PlayList is Empty";
			return;
		}
		int i=front;
		while(true){
			cout<<song[i]<<endl;
			if(i==rear){
				break;
			}
			i=(i+1)%capacity;
		}
	}
};
int main(){
	Playlist p;
	p.addSongs("Song 1");
	p.addSongs("Song 2");
	p.addSongs("Song 3");
	p.addSongs("Song 4");
	p.addSongs("Song 5");
	cout<<"Displaying Playlist"<<endl;
	p.display();
	p.PlayNext();
	p.PlayNext();
}