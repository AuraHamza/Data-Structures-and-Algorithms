//String Circular Queue://
//Implement a circular queue to store 5 song names.
////Add functions: addSong() (enqueue), playNext() (dequeue), display().
#include<iostream>
using namespace std;
class Playlist{
	int front ,rear;
	string song[5];
	int capacity;
	public:
		Playlist(){
			front=-1;
			rear=-1;
			capacity=5;
		}
		bool isEmpty(){
			return (front==-1 && rear==-1);
		}
		void addSong(string s){
			if((rear+1)%capacity==front){
				cout<<"Queue Overflow"<<endl;
				return;
			}
			if(front==-1 && rear==-1){
				front=rear=0;
				song[rear]=s;
				return;
			}
			else{
				rear=(rear+1)%capacity;
				song[rear]=s;
			}
		}
		void PlayNext(){
			if(isEmpty()){
				cout<<"Queue UnderFlow"<<endl;
			}
			if(front==rear){
				front=rear=-1;
				return;
			}
			else{
				front=(front+1)%capacity;

			}
		}
		void Display(){
			if(isEmpty()){
				cout<<"Queue is Empty";
				return;
			}
			int i=front;
			cout<<"Songs are: "<<endl;
			while(true){
				cout<<i+1<<")"<<song[i]<<endl;
				if(i==rear){
					break;
				}
				i=(i+1)%capacity;
			}
		}
};
int main(){
	Playlist p;
	p.addSong("Tera Naam");
	p.addSong("Hahah");
	p.addSong("Dico");
	p.addSong("Rose");
	p.addSong("JOke");
	p.Display();
	cout<<"After deleting 2"<<endl;
	p.PlayNext();
	p.PlayNext();
	p.Display();
	p.addSong("Rose");
	p.addSong("JOke");
	p.Display();
}