#include <iostream>
using namespace std;

int main() {
    int B[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout << "B       = " << B << endl;
    cout << "B+1     = " << B+1 << endl;
    cout << "B+2     = " << B+2 << endl;

//    cout << "*B      = " << *B << endl;
//    cout << "*B+1    = " << *B+1 << endl;
//    cout << "*B+2    = " << *B+2 << endl;
//
//    cout << "B[0]    = " << B[0] << endl;
//    cout << "B[0]+1  = " << B[0]+1 << endl;
//    cout << "B[0]+2  = " << B[0]+2 << endl;

    return 0;
}

