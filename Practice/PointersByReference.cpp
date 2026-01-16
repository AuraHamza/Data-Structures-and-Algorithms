#include<iostream>
using namespace std;

void func(int &a) {   
    *a = *a + 1;     
    cout << "func = " << *a << endl;
}

int main(){
    int a = 5;
//    int *p=&a;
    func(a);
	
	
}

