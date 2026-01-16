#include <iostream>
using namespace std;

class Package {
public:
    string id;
    int time;

    Package() {
        id = "";
        time = 0;
    }
    Package(string i, int t) {
        id = i;
        time = t;
    }
};

class MinHeap {
public:
    Package arr[100];
    int size = 0;

    void insert(Package p) {
        size++;
        arr[size] = p;

        int i = size;
        while (i > 1) {
            int parent = i / 2;

            // Compare on arrival time
            if (arr[parent].time > arr[i].time) {
                swap(arr[parent], arr[i]);
                i = parent;
            } else {
                break;
            }
        }
    }

    Package Delete() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return Package("", -1);
        }

        Package root = arr[1];
        arr[1] = arr[size];
        size--;

        int i = 1;
        while (true) {
            int left = 2 * i;
            int right = left + 1;
            int smallest = i;

            if (left <= size && arr[left].time < arr[smallest].time)
                smallest = left;
            if (right <= size && arr[right].time < arr[smallest].time)
                smallest = right;

            if (smallest == i)
                break;

            swap(arr[i], arr[smallest]);
            i = smallest;
        }

        return root;
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i].id << "(" << arr[i].time << ") ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap h;

    // Insert given packages
    h.insert(Package("pkg1", 45));
    h.insert(Package("pkg2", 20));
    h.insert(Package("pkg3", 35));
    h.insert(Package("pkg4", 10));
    h.insert(Package("pkg5", 50));
    h.insert(Package("pkg6", 30));
    h.insert(Package("pkg7", 25));

    cout << "First 3 Packages to Process (Earliest Arrival): ";

    Package first3[3];
    for (int i = 0; i < 3; i++) {
        first3[i] = h.Delete();
        cout << first3[i].id << " ";
    }
    cout << endl;

    Package stack[100];
    int top = -1;

    while (h.size > 0) {
        stack[++top] = h.Delete();
    }

    cout << "Remaining Packages (Latest Arrival): ";
    while (top >= 0) {
        cout << stack[top].id << " ";
        top--;
    }

    return 0;
}
