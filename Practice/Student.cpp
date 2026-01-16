#include<iostream>
#include <cstring>
using namespace std;

class Student{
	public:
		char* name;
		int* mark;
		int numsubject;
		
		Student(){
			mark=NULL;
			numsubject=0;
			name=NULL;
		}
		
		Student(const char* na, int m[],int size){
			name=new char[strlen(na)+1];
			strcpy(name,na);
			 numsubject=size;
			 mark=new int[size];
			for(int i=0;i<numsubject;i++){
				 mark[i]=m[i];
			} 
		}
		
		Student(const Student& other){
			name=new char[strlen(other.name)+1];
			strcpy(name,other.name);
			numsubject=other.numsubject;
			mark=new int[numsubject];
			for(int i=0;i<numsubject;i++){
				mark[i]=other.mark[i];
			}
		}
		
		Student& operator=(const Student& other){
			if(this!=&other){
				delete[] mark;
				delete[] name;
			
			name=new char[strlen(other.name)+1];
			strcpy(name,other.name);
			numsubject=other.numsubject;
			for(int i=0;i<numsubject;i++){
				mark[i]=other.mark[i];
			}
		}
		return *this;
		}
		
	~Student(){
		cout << "Destructor called for " << name << endl;
		delete[] name;
		delete[] mark;
	}
	
	int avg(){
		int sum=0;
		for(int i=0;i<numsubject;i++){
			sum+=mark[i];
		}
		return sum/numsubject;
	}
	void display(){
		cout<<"Name"<< name<<"\n marks:";
		for(int i=0;i<numsubject;i++){
			cout<<mark[i]<<" ";
		}
		cout<<"\nAverage: "<<avg();
	}
};
int main() {
    int marks1[] = {85, 90, 78};
    Student s1("Ali", marks1, 3);

    Student s2 = s1; // Copy constructor

    int marks2[] = {70, 65, 80};
    Student s3("Ahmed", marks2, 3);

    s3 = s1; // Copy assignment

    s1.display();
    s2.display();
    s3.display();

    return 0;
}
