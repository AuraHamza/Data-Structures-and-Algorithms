#include<iostream>
using namespace std;

class FruitShopInventory{
	int** inventory;
	int friutquantity;
	public:
		FruitShopInventory (int n, int initialquantity, int price)
		{
			inventory=new int*[friutquantity];
			     friutquantity=n; 
			for(int i=0;i<friutquantity;i++){
				inventory[i]=new int [2];
                inventory[i][0] =initialquantity;
 				inventory[i][1]=price;
			}
		}
	FruitShopInventory(const FruitShopInventory& other){
		friutquantity=other.friutquantity;
		inventory=new int*[friutquantity];
		for(int i=0;i<friutquantity;i++){
			inventory[i] = new int[2];
            inventory[i][0] = other.inventory[i][0];
            inventory[i][1] = other.inventory[i][1];
		}
	}
	FruitShopInventory & operator=(const FruitShopInventory & other){
		if(this !=&other){
			for(int i=0;i<friutquantity;i++){
				delete[] inventory[i];
			}
			delete[] inventory;
			
			friutquantity=other.friutquantity;
            inventory = new int*[friutquantity];
            for (int i=0;i<friutquantity;i++) {
                inventory[i]=new int[2];
                inventory[i][0]=other.inventory[i][0];
                inventory[i][1]=other.inventory[i][1];
		}
	}
	return *this;
}
~FruitShopInventory (){
	for(int i=0;i<friutquantity;i++){
		delete[] inventory[i];
	}
		delete[] inventory;
}
 void displayInventory() const {
        cout <<"\nFruit Inventory (Qty, Price):\n";
        for (int i = 0; i <friutquantity; i++) {
            cout << "Fruit " <<i+1<< "Qty: "<<inventory[i][0]<<", Price: "<< inventory[i][1] << endl;
        }
    }
    void updateFruit(int index,int quantity,int price){
	if(index >= 0 && index<friutquantity){
		inventory[index][0]=quantity;
		inventory[index][1]=price;
	}else{
		cout<<"Invalid Index!";
	}
}
};


int main() {
    FruitShopInventory shop(3, 50, 100); 
    cout << "Original Inventory:"; 
    shop.displayInventory();
    
    FruitShopInventory copyShop = shop;
    shop.updateFruit(1, 30, 120); 

    cout << "After Modification in Original:";
    shop.displayInventory();

    cout <<"Copied Inventory:";
    copyShop.displayInventory();

    return 0;
}
