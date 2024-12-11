//STT: 23
//Full name: Le Hoang Thien Phu
//Exercise 07
//Notes or Remarks: ......

//Write a function to find the lowest common ancestor of two given nodes in a binary search tree.
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

    Node* findLCA(Node* node, int n1, int n2) {
        if (node == nullptr) return nullptr;

        if (node->data > n1 && node->data > n2) {
            return findLCA(node->left, n1, n2);
        }

        if (node->data < n1 && node->data < n2) {
            return findLCA(node->right, n1, n2);
        }

        return node;
    }
};

int main() {
    BinarySearchTree bst;
    int n, value, n1, n2;

    cout << "Enter the number of elements to insert: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        bst.insert(bst.root, value);
    }

    cout << "Enter two nodes to find their LCA: ";
    cin >> n1 >> n2;

    Node* lca = bst.findLCA(bst.root, n1, n2);
    if (lca) {
        cout << "The LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    } else {
        cout << "No common ancestor found." << endl;
    }

    return 0;
}
