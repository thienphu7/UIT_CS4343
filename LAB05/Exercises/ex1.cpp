//STT: 23
//Full name: Le Hoang Thien Phu
//Exercise 01
//Notes or Remarks: ......

//1. Implement a binary tree class with methods for insertion, deletion, and searching for values.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* makeNode(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    // Insert a value into the binary tree
    void insert(Node*& node, int x) {
        if (node == nullptr) {
            node = makeNode(x);
        } else if (x < node->data) {
            insert(node->left, x);
        } else {
            insert(node->right, x);
        }
    }

    // Search for a value in the binary tree
    bool search(Node* node, int x) {
        if (node == nullptr) return false;
        if (node->data == x) return true;
        if (x < node->data) return search(node->left, x);
        return search(node->right, x);
    }

    // Delete a value from the binary tree
    Node* deleteNode(Node* node, int x) {
        if (node == nullptr) return node;
        if (x < node->data) {
            node->left = deleteNode(node->left, x);
        } else if (x > node->data) {
            node->right = deleteNode(node->right, x);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // Find the minimum node in the tree
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};

int main() {
    BinaryTree tree;
    int n, value;

    cout << "Enter the number of elements to insert: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(tree.root, value);
    }

    cout << "Enter value to search: ";
    cin >> value;
    cout << "Searching for " << value << ": " << (tree.search(tree.root, value) ? "Found" : "Not Found") << endl;

    cout << "Enter value to delete: ";
    cin >> value;
    tree.root = tree.deleteNode(tree.root, value);
    cout << "After deleting " << value << ": " << (tree.search(tree.root, value) ? "Found" : "Not Found") << endl;

    return 0;
}
