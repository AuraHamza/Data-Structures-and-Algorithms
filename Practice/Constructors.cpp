#include <iostream>
using namespace std;

class Number {
    int n;
    
public:
    Number(int value) {  
        n = value;
    }
     Number() {  
        cout<<"default";
    }

    Number(const Number &obj) {  
        n = obj.n;
    }

    void display() {
        cout << "Value of n: " << n << endl;
    }
};

int main() {
    Number a(10),d;     
    Number b(a); 
	Number c=a;
	d=a;
    return 0;
}

