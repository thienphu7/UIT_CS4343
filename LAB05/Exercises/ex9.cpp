//STT: 23
//Full name: Le Hoang Thien Phu
//Exercise 09
//Notes or Remarks: ......

//Write a function to find the maximum path sum in a binary tree, where the path may start and end at any node.
#include <iostream>
#include <climits>
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

    int maxPathSumUtil(Node* node, int& maxSum) {
        if (node == nullptr) return 0;

        int left = max(0, maxPathSumUtil(node->left, maxSum));
        int right = max(0, maxPathSumUtil(node->right, maxSum));

        maxSum = max(maxSum, left + right + node->data);

        return max(left, right) + node->data;
    }

    int maxPathSum(Node* root) {
        int maxSum = INT_MIN;
        maxPathSumUtil(root, maxSum);
        return maxSum;
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

    cout << "Maximum Path Sum: " << tree.maxPathSum(tree.root) << endl;

    return 0;
}
