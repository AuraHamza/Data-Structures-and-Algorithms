#include <iostream>
using namespace std;

class ProductStockManager {
    int* stock;    
    int size;      

public:
    ProductStockManager(int n,int initialStock) {
        size=n;
        stock=new int[size];
        for (int i=0;i<size;i++) {
            stock[i]=initialStock;
        }
    }

    ProductStockManager(const ProductStockManager& other) {
        size=other.size;
        stock=new int[size];
        for (int i=0; i<size;i++) {
            stock[i]=other.stock[i];
        }
    }

    ProductStockManager& operator=(const ProductStockManager& other) {
        if (this != &other) {
            delete[] stock;
            size=other.size;
            stock=new int[size];
            for (int i=0;i<size;i++) {
                stock[i]=other.stock[i];
            }
        }
        return *this;
    }

    ~ProductStockManager() {
        delete[] stock;
    }

    int& operator[](int index) {
        if (index<0 || index>=size) {
            cout<<"Error:Index out of bounds!"<<endl;
            exit(1);
        }
        return stock[index];
    }

    void display(){
        for (int i = 0; i < size; i++){
            cout <<"Product"<<i<<"stock: "<<stock[i]<<endl;
        }
    }
};

int main() {
    ProductStockManager p1(3, 50);
    ProductStockManager p2 = p1;
    cout << "p2 stock before changes:" << endl;
    p2.display();
    p2[1] = 100;
    cout << "p1 stock:" << endl;
    p1.display();
    cout << "p2 stock:" << endl;
    p2.display();

    return 0;
}

