//STT: 23
//Full name: Le Hoang Thien Phu
//Exercise 06
//Notes or Remarks: ......

/*Implement a function to determine if a binary tree is height-balanced (where the height of the
 two subtrees of any node differs by no more than one).*/
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

    bool isBalanced(Node* node) {
        if (node == nullptr) return true;

        int lh = height(node->left);
        int rh = height(node->right);

        return abs(lh - rh) <= 1 && isBalanced(node->left) && isBalanced(node->right);
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

    cout << "Is the tree height-balanced? " << (tree.isBalanced(tree.root) ? "Yes" : "No") << endl;

    return 0;
}
