#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node(int value) {
        data = value;
        left = right = next = nullptr;
    }
};

// Insert into normal BST
Node* Insert(Node* head, int data) {
    if (head == nullptr)
        return new Node(data);

    if (data > head->data)
        head->right = Insert(head->right, data);
    else
        head->left = Insert(head->left, data);

    return head;
}

// Step 1: Store inorder traversal
void Inorder(Node* head, vector<int>& inorderVal) {
    if (head == nullptr) return;
    Inorder(head->left, inorderVal);
    inorderVal.push_back(head->data);
    Inorder(head->right, inorderVal);
}

// Step 2: Convert sorted inorder -> Balanced BST
Node* InorderToBST(int s, int e, vector<int>& inorder) {
    if (s > e) return nullptr;

    int mid = (s + e) / 2;
    Node* head = new Node(inorder[mid]);
    head->left = InorderToBST(s, mid - 1, inorder);
    head->right = InorderToBST(mid + 1, e, inorder);

    return head;
}

// Step 3: Convert normal BST -> Balanced BST
Node* BalanceBST(Node* head) {
    vector<int> inorderVal;
    Inorder(head, inorderVal);
    return InorderToBST(0, inorderVal.size() - 1, inorderVal);
}

// Preorder print
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = nullptr;

    // Insert in unbalanced order (right skewed)
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 40);
    root = Insert(root, 50);

    cout << "Before balancing (Preorder): ";
    preorder(root);
    cout << endl;

    // Balance the BST
    root = BalanceBST(root);

    cout << "After balancing (Preorder): ";
    preorder(root);
    cout << endl;

    return 0;
}
