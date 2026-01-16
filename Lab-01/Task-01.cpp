#include<iostream>
using namespace std;
class BankAccount{
	public:
	int balance;
	BankAccount()
	{
		this->balance=0;
		cout<<"Account1: "<<balance<<endl;
	}
		BankAccount(int balance)
	{
		this->balance=balance;
		cout<<"Account2: "<<balance<<endl;
	}
		BankAccount(const BankAccount& other)
	{
		balance=other.balance;
		cout<<"Account3: "<<balance<<endl;
	}
	
};
int main(){
	BankAccount Obj1;
	BankAccount Obj2(1000);
	BankAccount Obj3= Obj2;
	Obj3.balance=Obj3.balance-200;
	cout<<"Account3:"<<Obj3.balance;
	return 0;
}


