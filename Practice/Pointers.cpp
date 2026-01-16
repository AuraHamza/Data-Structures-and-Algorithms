#include <iostream>
using namespace std;

int main() {
    int var = 25;          // simple variable
    int *ptr = &var;       // pointer to var (stores address of var)
    int **pptr = &ptr;     // pointer to pointer (stores address of ptr)

    cout << "var = " << var << endl;
    cout << "&var (address of var) = " << &var << endl;
    cout << "ptr (address stored in ptr) = " << ptr << endl;
    cout << "*ptr (value at that address) = " << *ptr << endl;
    cout << "&ptr (address of ptr) = " << &ptr << endl;
    cout << "pptr (address stored in pptr) = " << pptr << endl;
    cout << "*pptr (value at that address i.e. ptr) = " << *pptr << endl;
    cout << "**pptr (value at that address i.e. var) = " << **pptr << endl;

    return 0;
}

