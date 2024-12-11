//STT: 23
//Full name: Le Hoang Thien Phu
//Exercise 02
//Notes or Remarks: ......

// Write functions to perform pre-order, in-order, post-order, and level-order traversals of a binary tree.
#include <iostream>
#include <queue>
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

void preOrder(Node* node) {
    if (node) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(Node* node) {
    if (node) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(Node* node) {
    if (node) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

int main() {
    Node* root = nullptr;
    int n, value;

    cout << "Enter the number of elements to insert: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        if (root == nullptr) {
            root = makeNode(value);
        } else {
            queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                Node* temp = q.front();
                q.pop();
                if (value < temp->data) {
                    if (temp->left == nullptr) {
                        temp->left = makeNode(value);
                        break;
                    } else {
                        q.push(temp->left);
                    }
                } else {
                    if (temp->right == nullptr) {
                        temp->right = makeNode(value);
                        break;
                    } else {
                        q.push(temp->right);
                    }
                }
            }
        }
    }

    cout << "Pre-Order Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "In-Order Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Post-Order Traversal: ";
    postOrder(root);
    cout << endl;

    cout << "Level-Order Traversal: ";
    levelOrder(root);
    cout << endl;

    return 0;
}
