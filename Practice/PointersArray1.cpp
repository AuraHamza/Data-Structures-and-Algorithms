#include <iostream>
using namespace std;

int main() {
    int A[5] = {10, 20, 30, 40, 50};

    cout << "Accessing using A[i]: " << endl;
    for (int i = 0; i < 5; i++) {
        cout<< i << " = " << A[i] << endl;
    }

    cout << "\nAccessing using *(A+i): " << endl;
    for (int i = 0; i < 5; i++) {
        cout<< i << " = " << *(A + i) << endl;
    }

    return 0;
}

