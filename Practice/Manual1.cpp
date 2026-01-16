#include<iostream>
using namespace std;
class BankManager{
	public:
		int balance ;
		BankManager(){
			balance=1000;
			cout<<"Default constructor $ "<<balance<<endl;	
		}
		BankManager(int b){
			this->balance=b;
			cout<<"Parametrize Construtor: "<<this->balance<<endl;

		}
		BankManager(const BankManager& other){
		  this->balance=other.balance;
			cout<<"Copy Construtor: "w<<this->balance<<endl;
		}
};
int main(){
	BankManager A1;
	BankManager A2(1000);
	BankManager A3=A2;
	A3.balance=A3.balance-200;
	cout<<"A3: "<<A3.balance;
	
}
