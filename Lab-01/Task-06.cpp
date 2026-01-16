#include <iostream>
#include <cstring>
using namespace std;

class Shop {
public:
	char* productName;
    int* quantities;
    int branches;

    Shop(int n, const char* name) {
        branches = n;
        productName = new char[strlen(name) + 1];
        strcpy(productName, name);
        quantities = new int[branches];
        for (int i = 0; i < branches; i++)
            quantities[i] = 0;
    }

    Shop(const Shop& other) {
        branches = other.branches;
        productName = new char[strlen() + 1];
        strcpy(productName, other.productName);
        quantities = new int[branches];
        for (int i = 0; i < branches; i++)
            quantities[i] = other.quantities[i];
    }

    Shop& operator=(const Shop& other) {
        if (this != &other) {
            delete[] productName;
            delete[] quantities;
            branches = other.branches;
            productName = new char[strlen(other.productName) + 1];
            strcpy(productName, other.productName);
            quantities = new int[branches];
            for (int i = 0; i < branches; i++)
                quantities[i] = other.quantities[i];
        }
        return *this;
    }

    ~Shop() {
        delete[] productName;
        delete[] quantities;
    }

    void setQuantity(int branchIndex, int qty) {
        if (branchIndex >= 0 && branchIndex < branches)
            quantities[branchIndex] = qty;
    }

    void display() {
        cout<<"Product Name: "<<productName<<endl;
        cout<<"Quantities in Branches: ";
        for (int i = 0; i < branches; i++)
            cout << quantities[i] << " ";
        cout << endl;
    }
};

int main() {
    Shop shop1(4,"Refrigerator");
    shop1.setQuantity(0,12);
    shop1.setQuantity(1,7);
    shop1.setQuantity(2,15);
    shop1.setQuantity(3,9);

    cout<<"Shop 1 details:"<<endl;
    shop1.display();

    Shop shop2=shop1;
    cout<<"Shop 2 details:"<<endl;
    shop2.display();

    Shop shop3(2, "Microwave");
    shop3.setQuantity(0,3);
    shop3.setQuantity(1,4);
    cout<<"Shop 3 details:"<<endl;
    shop3.display();

    shop3 = shop1;
    cout << "Shop 3 details:"<<endl;
    shop3.display();

    return 0;
}

