#include <iostream>
using namespace std;

#define Size 10

// HashItem class
class HashItem {
public:
    int key;
    int value;
    bool occupied;

    HashItem() {
        key = 0;
        value = 0;
        occupied = false;
    }
};

// Hash table class
class Hashtable {
private:
    HashItem table[Size];

    int hashFunction(int key) {
        return key % Size;
    }

public:
    // Constructor
    Hashtable() {
        for (int i = 0; i < Size; i++)
            table[i].occupied = false;
    }

    // i. Insert duplicates using linear probing
    void LinearProbingHashDuplicates(int key, int value) {
        int index = hashFunction(key);
        int start = index;

        while (table[index].occupied) {
            index = (index + 1) % Size;
            if (index == start) {
                cout << "Hash table is full" << endl;
                return;
            }
        }

        table[index].key = key;
        table[index].value = value;
        table[index].occupied = true;
    }

    // ii. Return all values for a key
    void ReturnValues(int key) {
        bool found = false;
        for (int i = 0; i < Size; i++) {
            if (table[i].occupied && table[i].key == key) {
                cout << table[i].value << " ";
                found = true;
            }
        }
        if (!found)
            cout << "Koi value nhi";
        cout << endl;
    }

    // iii. Remove all items with a given key
    void RemoveKey(int key) {
        for (int i = 0; i < Size; i++) {
            if (table[i].occupied && table[i].key == key)
                table[i].occupied = false;
        }
    }

    // Display table
    void Display() {
        for (int i = 0; i < Size; i++) {
            if (table[i].occupied)
                cout << "[" << i << "] Key: " << table[i].key << ", Value: " << table[i].value << endl;
            else
                cout << "[" << i << "] Empty" << endl;
        }
    }
};

int main() {
    Hashtable hashTable;

    // Insert duplicates
    hashTable.LinearProbingHashDuplicates(1, 100);
    hashTable.LinearProbingHashDuplicates(1, 200);
    hashTable.LinearProbingHashDuplicates(11, 300);
    hashTable.LinearProbingHashDuplicates(21, 400);

    cout << "Initial table:\n";
    hashTable.Display();

    // Return all values for key 1
    cout << "\nValues for key 1: ";
    hashTable.ReturnValues(1);

    // Remove key 1
    hashTable.RemoveKey(1);
    cout << "\nTable after removing key 1:\n";
    hashTable.Display();

    return 0;
}
