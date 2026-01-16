#include <iostream>
using namespace std;

class Box {
public:
	   int* value;
    Box(int v = 0) {
        value = new int;
        *value = v;
    }

    ~Box() {
        delete value;
    }

    Box(const Box& other) {
        value = new int;
        *value = *other.value;
    }

    Box& operator=(const Box& other) {
        if (this != &other) {
            delete value;
            value = new int;
            *value = *other.value;
        }
        return *this;
    }

    void setValue(int v){
	 *value = v;
	}
    int getValue() const{
	 return *value; 
   }
};

int main() {
    cout << "Deep Copy"<<endl;
    Box b1(2);
    Box b2 = b1;
    b2.setValue(5);

    cout << "Box1 value: "<< b1.getValue()<< endl;
    cout << "Box2 value: "<< b2.getValue()<< endl;

    cout << "\nAssignment Operator"<<endl;
    Box b3(50);
    Box b4;
    b4 = b3;
    b4.setValue(35);

    cout<<"Box3 value: "<<b3.getValue()<< endl;
    cout<<"Box4 value: "<<b4.getValue()<< endl;

    return 0;
}

