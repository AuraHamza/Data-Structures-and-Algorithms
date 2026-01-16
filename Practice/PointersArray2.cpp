#include<iostream>
#include<string.h>
using namespace std;
int main(){
	char C1[12]={'H','e','l','l','o','\0'};
	char* C2;
	C2=C1;
	cout<<"Only accessing the value:"<<endl;
    cout << "C1[1]    = " << C1[1] << endl;     // array indexing
    cout << "*(C1+1)  = " << *(C1+1) << endl;   // pointer arithmetic
    cout << "C2[1]    = " << C2[1] << endl;     // pointer indexing
    cout << "*(C2+1)  = " << *(C2+1) << endl;   // pointer arithmetic on C2
    C2[1]='a';
    cout<<"After changing index 1 by pointer  "<<endl;
    cout << "C1[1]    = " << C1[1] << endl;     // array indexing
    cout << "*(C1+1)  = " << *(C1+1) << endl;   // pointer arithmetic
    cout << "C2[1]    = " << C2[1] << endl;     // pointer indexing
    cout << "*(C2+1)  = " << *(C2+1) << endl;   // pointer arithmetic on C2]
    
    C1[1]='b';
    cout<<"After changing index 1 by array  "<<endl;
    cout << "C1[1]    = " << C1[1] << endl;     // array indexing
    cout << "*(C1+1)  = " << *(C1+1) << endl;   // pointer arithmetic
    cout << "C2[1]    = " << C2[1] << endl;     // pointer indexing
    cout << "*(C2+1)  = " << *(C2+1) << endl;   // pointer arithmetic on C2]
    
    
    

}
