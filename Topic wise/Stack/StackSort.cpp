#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int> &s) {
    stack<int> tempStack;

    while (!s.empty()) {
        int temp = s.top();
        s.pop();

        // Move elements bigger than temp back to original
        while (!tempStack.empty() && tempStack.top() > temp) {
            s.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(temp);
    }

    // Move back to original stack (sorted ascending)
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack<int> s;
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);

    sortStack(s);

    cout << "Sorted Stack (Top to Bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
