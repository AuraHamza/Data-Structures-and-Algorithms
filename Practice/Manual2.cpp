#include<iostream>
#include<cstring>
using namespace std; 
class Exam{
	public:
		char *name;
		char* date;
		int* score;
		Exam(){
			this->name=NULL;
			this->date=NULL;
			this->score=NULL;
		}
		Exam(const char* n,const char* d,int s){
			this->name=new char[strlen(n)+1];
			strcpy(name,n);
			this->date=new char[strlen(d)+1];
			strcpy(date,d);
			this->score=new int(s);
		}
		void set(int s,const char* d,const char* n){
			delete[] name;
			delete[] date;
			delete[] score;
			this->name=new char[strlen(n)+1];
			strcpy(name,n);
			this->date=new char[strlen(d)+1];
			strcpy(date,d);
			this->score=new int(s);
		}
		void display(){
			cout<<"Name: "<<this->name<<endl<<"Date: "<<this->date<<endl<<"Score: "<<*this->score<<endl;	
		}
		~Exam(){
			delete[] name;
			delete[] date;
			delete[] score;
		}
};
int main(){
	Exam s1("Hamza","12-6-2025",98);
	cout<<"Frist student"<<endl;
	s1.display();
	
	Exam s2=s1;
	cout<<"Copy student2 from student1"<<endl;
	s2.display();
	s2.set(87,"13-6-2025","Ibrahim");
	cout<<"After changing values"<<endl;
	s2.display();
}
