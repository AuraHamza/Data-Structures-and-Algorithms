#include<iostream>
#include<cstring>
using namespace std;
class Document{
	public:
	char* content;
	Document(){
		this->content=NULL;
	}
	Document(const char* c){
		content=new char[strlen(c)+1];
		strcpy(content,c);
	} 
	Document(const Document& other){
		content=new char[strlen(other.content)+1];
		strcpy(content,other.content);
	}
	Document& operator=(const Document& other){
		if(this!=&other){
			delete[]content;
			content=new char[strlen(other.content)+1];
			strcpy(content,other.content);
		}
		return *this;
	}
	void display(){
		cout<<content<<endl;
	}
	~Document() {
    delete[] content;
}

};

int main(){
	Document d1("hamza is sleeping");
	Document d2("Ibrahim is noob");
	d1.display();
	d2.display();
	d2=d1;
	d2.display();
	
}
