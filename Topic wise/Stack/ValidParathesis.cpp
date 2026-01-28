#include<iostream>
#include <cstring>
using namespace std;

class Stack{
	char c[100];
	int top;
	public:
	Stack(){
		top=-1;
	}
	void push(char value){
		if(top>99){
			cout<<"Stack Overflow";
			return ;
		}
		top++;
		c[top]=value;
	}
	void pop(){
		if(isEmpty()){
			cout<<"Stack underFolw";
			return;
		}
		top--;
	}
	char peek(){
		if(isEmpty()){
			cout<<"Stack is Empty";
			return '\0';
		}
		return c[top];
	}
	bool isEmpty(){
		return top==-1;
	}
};
bool ValidParenthises(string infix,int size){
	Stack s;
	string postfix="";
	int i=0;
	while(i<size){
//		if see any open bracket
         char c=infix[i];
        if(c=='(' || c=='[' || c=='{'){
        	s.push(c);
		}
		else if(c==')'){
			if(s.isEmpty() ||s.peek()!='('){
				return false;
			}
			s.pop();
		}
		else if(c==']'){
			if(s.isEmpty() ||s.peek()!='['){
				return false;
			}
			s.pop();
		}
		else if(c=='}'){
			if(s.isEmpty() ||s.peek()!='{'){
				return false;
			}
			s.pop();
		}
		i++;
	}
	return s.isEmpty();
}
int main(){
	string br;
	cout<<"Enter String of Brackets: ";
	cin>>br;
	int size=br.length();
	if(ValidParenthises(br,size)){
		cout<<"valid";
	}else{
		cout<<"Invalid";
	}
	return 0;
}