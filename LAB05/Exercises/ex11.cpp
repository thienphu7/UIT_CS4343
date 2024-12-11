//STT: 23
//Full name: Le Hoang Thien Phu
//Exercise 11
//Notes or Remarks: ......

//Implement vertical order traversal of a binary tree and return the values in vertical slices.
#include <iostream>
#include <vector>
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

    void displayTree(Node* node, int level = 0, string branch = "Root") {
        if (node == nullptr) return;

        // Display the current node with its branch and level
        for (int i = 0; i < level; i++) cout << "    ";
        cout << branch << ": " << node->data << endl;

        // Recurse for left and right subtrees
        displayTree(node->left, level + 1, "Left");
        displayTree(node->right, level + 1, "Right");
    }

    void verticalOrder(Node* node, vector<int>& result, int column, int targetColumn) {
        if (node == nullptr) return;

        // Add the node's data to the result if it matches the target column
        if (column == targetColumn) {
            result.push_back(node->data);
        }

        // Recurse for left and right subtrees with adjusted column values
        verticalOrder(node->left, result, column - 1, targetColumn);
        verticalOrder(node->right, result, column + 1, targetColumn);
    }

    void printVerticalOrder(Node* root) {
        int minColumn = 0, maxColumn = 0;

        // Find the range of column indices
        findColumnRange(root, 0, minColumn, maxColumn);

        // Print nodes in each column
        for (int col = minColumn; col <= maxColumn; col++) {
            vector<int> result;
            verticalOrder(root, result, 0, col);
            cout << "Column " << col << ": ";
            for (int val : result) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    void findColumnRange(Node* node, int column, int& minColumn, int& maxColumn) {
        if (node == nullptr) return;

        // Update the range of columns
        if (column < minColumn) minColumn = column;
        if (column > maxColumn) maxColumn = column;

        // Recurse for left and right subtrees
        findColumnRange(node->left, column - 1, minColumn, maxColumn);
        findColumnRange(node->right, column + 1, minColumn, maxColumn);
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

    cout << "\nTree structure:\n";
    tree.displayTree(tree.root);

    cout << "\nVertical Order Traversal:\n";
    tree.printVerticalOrder(tree.root);

    return 0;
}