
//STT: 23
//Full name: Le Hoang Thien Phu
//Exercise 03
//Notes or Remarks: ......

/*Extend the binary tree class to implement a binary search tree with methods for finding
 minimum and maximum values, checking if the tree is balanced, and calculating its height.*/
#include <iostream>
#include <cmath>
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

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(Node*& node, int x) {
        if (node == nullptr) {
            node = makeNode(x);
        } else if (x < node->data) {
            insert(node->left, x);
        } else {
            insert(node->right, x);
        }
    }

    int findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->data;
    }

    int findMax(Node* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node->data;
    }

    int height(Node* node) {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    bool isBalanced(Node* node) {
        if (node == nullptr) return true;
        int lh = height(node->left);
        int rh = height(node->right);
        return abs(lh - rh) <= 1 && isBalanced(node->left) && isBalanced(node->right);
    }
};

int main() {
    BinarySearchTree bst;
    int n, value;

    cout << "Enter the number of elements to insert: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        bst.insert(bst.root, value);
    }

    cout << "Minimum value: " << bst.findMin(bst.root) << endl;
    cout << "Maximum value: " << bst.findMax(bst.root) << endl;
    cout << "Height of tree: " << bst.height(bst.root) << endl;
    cout << "Is the tree balanced? " << (bst.isBalanced(bst.root) ? "Yes" : "No") << endl;

    return 0;
}