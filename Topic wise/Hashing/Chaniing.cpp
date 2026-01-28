#include <iostream>
using namespace std;

#define INITIAL_TABLE_SIZE 10
#define LOAD_FACTOR_THRESHOLD 0.7

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class HashTable {
    Node** table;
    int tableSize;
    int currentSize;

    int HashFunction(int value) {
        return value % tableSize;
    }

    float loadFactor() {
        return (float)currentSize / tableSize;
    }

    void rehash() {
        int oldTableSize = tableSize;
        tableSize *= 2; // double the table size
        Node** oldTable = table;

        table = new Node*[tableSize];
        for (int i = 0; i < tableSize; i++)
            table[i] = nullptr;

        currentSize = 0;

        for (int i = 0; i < oldTableSize; i++) {
            Node* curr = oldTable[i];
            while (curr) {
                insert(curr->data); // re-insert into new table
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] oldTable;
    }

public:
    HashTable() {
        tableSize = INITIAL_TABLE_SIZE;
        currentSize = 0;
        table = new Node*[tableSize];
        for (int i = 0; i < tableSize; i++)
            table[i] = nullptr;
    }

    ~HashTable() {
        for (int i = 0; i < tableSize; i++) {
            Node* curr = table[i];
            while (curr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] table;
    }

    void insert(int value) {
        int index = HashFunction(value);
        Node* newNode = new Node(value);

        newNode->next = table[index];
        table[index] = newNode;
        currentSize++;

        if (loadFactor() > LOAD_FACTOR_THRESHOLD)
            rehash();
    }

    bool search(int key) {
        int index = HashFunction(key);
        Node* curr = table[index];
        while (curr) {
            if (curr->data == key)
                return true;
            curr = curr->next;
        }
        return false;
    }

    void update(int oldValue, int newValue) {
        int index = HashFunction(oldValue);
        Node* curr = table[index];
        while (curr) {
            if (curr->data == oldValue) {
                curr->data = newValue;
                return;
            }
            curr = curr->next;
        }
        cout << "Value NOT found for update" << endl;
    }

    void Remove(int key) {
        int index = HashFunction(key);
        Node* curr = table[index];
        Node* prev = nullptr;

        while (curr) {
            if (curr->data == key) {
                if (prev)
                    prev->next = curr->next;
                else
                    table[index] = curr->next;
                delete curr;
                currentSize--;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Value NOT found for deletion" << endl;
    }

    void display() {
        for (int i = 0; i < tableSize; i++) {
            cout << i << "->";
            Node* curr = table[i];
            while (curr) {
                cout << curr->data << "->";
                curr = curr->next;
            }
            cout << "NULL" << endl;
        }
        cout << "Current table size: " << tableSize << ", Load factor: " << loadFactor() << endl;
    }
};

int main() {
    HashTable h;

    h.insert(12);
    h.insert(22);
    h.insert(32);
    h.insert(5);
    h.insert(15);
    h.insert(100);

    h.display();

    cout << "Search 22: " << (h.search(22) ? "Found" : "Not Found") << endl;

    h.update(15, 55);
    cout << "After updating 15 to 55:" << endl;
    h.display();

    h.Remove(100);
    cout << "After removing 100:" << endl;
    h.display();

    // Add more elements to trigger rehash
    h.insert(101);
    h.insert(102);
    h.insert(103);
    h.insert(104);
    cout << "After inserting more elements (rehash may occur):" << endl;
    h.display();

    return 0;
}
