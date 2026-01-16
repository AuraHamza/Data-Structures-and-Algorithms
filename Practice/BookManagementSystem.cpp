#include<iostream>
#include<cstring>
using namespace std;

class BookManagementSystem {
public:
    char* name;
    int id, experience;

    int* prebooks;
    int precount;

    int* newbooks;
    int newcount;

    BookManagementSystem(const char* n, int id, int exp, int preBook[], int size) {
        this->name = new char[strlen(n) + 1];
        strcpy(this->name, n);
        this->id = id;
        this->experience = exp;

        precount = size;
        prebooks = new int[size];
        for (int i = 0; i < size; i++) {
            prebooks[i] = preBook[i];
        }

        newbooks = NULL;
        newcount = 0;
    }

    void add() {
        cout << "Enter number of new books to add: ";
        cin >> newcount;

        newbooks = new int[newcount];
        cout << "Enter " << newcount << " new book IDs: ";
        for (int i = 0; i < newcount; i++) {
            cin >> newbooks[i];
        }
    }

    void display() {
        cout << "\n--- Librarian Info ---\n";
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Experience: " << experience << " years" << endl;

        cout << "\nPre-assigned Books: ";
        for (int i = 0; i < precount; i++) {
            cout << prebooks[i] << " ";
        }

        cout << "\nNewly Added Books: ";
        for (int i = 0; i < newcount; i++) {
            cout << newbooks[i] << " ";
        }
        cout << endl;
    }

    ~BookManagementSystem() {
        delete[] name;
        delete[] prebooks;
        delete[] newbooks;
    }
};

int main() {
    int id, exp;
    char name[40];

    cout << "Enter Librarian Name: ";
    cin >> name;
    cout << "Enter Librarian ID: ";
    cin >> id;
    cout << "Enter Years of Experience: ";
    cin >> exp;

    int preAssigned[] = {101, 102, 103};
    BookManagementSystem b1(name, id, exp, preAssigned, 3);

    b1.add();
    b1.display();

    return 0;
}

