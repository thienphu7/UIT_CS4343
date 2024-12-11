//STT: 23
//Full name: Le Hoang Thien Phu
//Exercise 12
//Notes or Remarks: ......

// Write an algorithm to find the lowest common ancestor (LCA) of two nodes in a binary tree.
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

        if (node->data == n1 || node->data == n2) return node;

        Node* leftLCA = findLCA(node->left, n1, n2);
        Node* rightLCA = findLCA(node->right, n1, n2);

        if (leftLCA && rightLCA) return node;

        return (leftLCA != nullptr) ? leftLCA : rightLCA;
    }
};

int main() {
    BinaryTree tree;
    int n, value, n1, n2;

    cout << "Enter the number of elements to insert: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(tree.root, value);
    }

    cout << "Enter two nodes to find their LCA: ";
    cin >> n1 >> n2;

    Node* lca = tree.findLCA(tree.root, n1, n2);
    if (lca) {
        cout << "The LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    } else {
        cout << "No common ancestor found." << endl;
    }

    return 0;
}
