#include<iostream>
using namespace std;
class Stack{
	char arr[100];
	int top=-1;
	public:
		void push(char ch){
			if(top>=99){
				cout<<"Stack Overflow";
				return;
			}
			top++;
			arr[top]=ch;
		}
		
		char pop(){
			if(top==-1){
				cout<<"Stack UnderFlow";
				return -1;
			}
			return arr[top--];
		}
		
		char peek(){
			if(top==-1){
				return -1;
			}
			return arr[top];
		}
		bool isEmpty(){
			if(top==-1){
				return true;
			}
			return false;
		}
};

int Precidence(char op){
	if(op=='^'){
		return 3;
	}
	 if(op=='*' || op=='/'){
		return 2;
	}
 if(op=='+' || op=='-'){
		return 1;
	}
	return 0;
}
bool Operand(char c){
	if((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')){
		return true;
	}
	return false;
}

string InfixToPostfix(string infix,int n){
	string postfix="";
	Stack st;
	int i=0;
	while(i<n){
		char c=infix[i];
		if(Operand(c)){
			postfix+=infix[i];
		}
		else if(c=='('){
			st.push(c);
		}
		else if(c==')'){
			while(!st.isEmpty() && st.peek()!='('){
				postfix+=st.pop();
			}
			st.pop();
		}
		else{
			while(!st.isEmpty() && Precidence(st.peek())>=Precidence(c)){
				postfix+=st.pop();
			}
			st.push(c);
		}
		i++;
	}
	while(!st.isEmpty()){
		postfix+=st.pop();
	}
	return postfix;
}
int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;
    int n=infix.length();
    cout << "Postfix Expression: " << InfixToPostfix(infix,n) << endl;

    return 0;
}



