#include <iostream>
using namespace std;
int main(){
	string name;
	int id,no_of_exp;
	int n;
	cout<<"Name of librarian: ";
	cin>>name;
	
	cout<<"ID:";
	cin>>id;
	
	cout<<"Number of experince:";
	cin>>no_of_exp;
	
	
    cout<<"Enter number of id's:";
	cin>>n;
	int* bookid=new int[n];
	for(int i=0;i<n;i++){
	cout<<"Book id:";
	cin>>bookid[i];
	}
	cout<<"Id are:";
	for(int i=0;i<n;i++){
	  cout << bookid[i] << " ";
	} 
    int bookids[5] = {101, 102, 103, 104, 105};
    cout << "\nFixed Book IDs in the library:\n";
    for (int i = 0; i < 5; i++) {
        cout << bookids[i] << " ";
    }
}

