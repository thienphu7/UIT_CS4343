//STT: 23
//Full name: Le Hoang Thien Phu
//Exercise 08
//Notes or Remarks: ......

//Implement level-order traversal of a binary tree using a queue and return the values in each level as separate lists.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {4
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

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; i++) {
                Node* currentNode = q.front();
                q.pop();
                currentLevel.push_back(currentNode->data);

                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);
            }

            result.push_back(currentLevel);
        }
        return result;
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

    vector<vector<int>> levels = tree.levelOrder(tree.root);
    cout << "Level-Order Traversal:" << endl;
    for (const auto& level : levels) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}