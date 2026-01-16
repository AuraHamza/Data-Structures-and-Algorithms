#include<iostream>
using namespace std;

class CircularQueue{
	string s[5];
	int front,rear;
	int capacity;
	
	public:
		CircularQueue(){
			front=0;
			rear=-1;
			capacity=5;
			
		}
		void addsongs(string value){
			rear=(rear+1)%capacity;
			s[rear]=value;
		}
		void playNext(){
			if(isEmpty()){
				cout<<"No songs to play";
				return ;
			}
			cout<<"Playing: "<<s[front]<<endl;
			front=(front+1)%capacity;
		}
		bool isEmpty(){
			if(capacity==0){
				return true;
			}
			return false;
		}
		void display(){
			if (isEmpty()) {
            cout << "Playlist is empty.\n";
            return;
        }
        cout<<"Current Playlist: ";
        int i=front;
        for(int j=0;j<capacity;j++){
        	cout<<s[i]<<" ";
        	i=(i+1)%capacity;
		}
		cout<<endl;
		}
};
int main(){
	CircularQueue c;
	c.addsongs("Song A");
	c.addsongs("Song B");
	c.addsongs("Song C");
	c.addsongs("Song D");
	c.addsongs("Song E");
	c.display();
	c.playNext();
	c.playNext();

	
}
