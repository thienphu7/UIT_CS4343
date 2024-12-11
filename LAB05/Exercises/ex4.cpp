//STT: 23
//Full name: Le Hoang Thien Phu
//Exercise 04
//Notes or Remarks: ......

//Write a function to calculate the diameter (the longest path between any two nodes) of a binary tree.
#include <iostream>
#include <algorithm>
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

    void insert(Node*& node, int x) {
        if (node == nullptr) {
            node = makeNode(x);
        } else if (x < node->data) {
            insert(node->left, x);
        } else {
            insert(node->right, x);
        }
    }

    int height(Node* node) {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    int diameter(Node* node) {
        if (node == nullptr) return 0;

        int lh = height(node->left);
        int rh = height(node->right);

        int leftDiameter = diameter(node->left);
        int rightDiameter = diameter(node->right);

        return max(lh + rh + 1, max(leftDiameter, rightDiameter));
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

    cout << "The diameter of the tree is: " << tree.diameter(tree.root) << endl;

    return 0;
}