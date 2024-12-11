//STT: 23
//Full name: Le Hoang Thien Phu
//Exercise 10
//Notes or Remarks: ......

// Given arrays representing the inorder and postorder traversals of a binary tree, reconstruct the original tree.
#include <iostream>
#include <vector>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to construct the binary tree
Node* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex) {
    if (inStart > inEnd)
        return nullptr;

    // The current root is the last element in the postorder array
    int rootValue = postorder[postIndex--];
    Node* root = new Node(rootValue);

    // Find the index of the root in the inorder array
    int inIndex = inStart;
    while (inIndex <= inEnd && inorder[inIndex] != rootValue)
        inIndex++;

    // Recursively build the right subtree, then the left subtree
    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

// Helper function to print the tree in inorder traversal
void printInorder(Node* root) {
    if (!root)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Helper function to print the tree in postorder traversal
void printPostorder(Node* root) {
    if (!root)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

// Helper function to print the tree in level order traversal for visualization
void printLevelOrder(Node* root) {
    if (!root)
        return;

    vector<Node*> currentLevel{root};

    while (!currentLevel.empty()) {
        vector<Node*> nextLevel;
        for (Node* node : currentLevel) {
            if (node) {
                cout << node->data << " ";
                nextLevel.push_back(node->left);
                nextLevel.push_back(node->right);
            } else {
                cout << "null ";
            }
        }
        currentLevel = nextLevel;
        cout << endl;
    }
}

int main() {
    // Test Case 1
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    vector<int> postorder1 = {9, 15, 7, 20, 3};

    // Build the tree
    int postIndex1 = postorder1.size() - 1;
    Node* root1 = buildTree(inorder1, postorder1, 0, inorder1.size() - 1, postIndex1);

    cout << "Test Case 1:\n";
    cout << "Inorder Traversal: ";
    printInorder(root1);
    cout << "\nPostorder Traversal: ";
    printPostorder(root1);
    cout << "\nLevel Order Traversal:\n";
    printLevelOrder(root1);
    cout << endl;

    // Test Case 2
    vector<int> inorder2 = {4, 2, 5, 1, 6, 3, 7};
    vector<int> postorder2 = {4, 5, 2, 6, 7, 3, 1};

    // Build the tree
    int postIndex2 = postorder2.size() - 1;
    Node* root2 = buildTree(inorder2, postorder2, 0, inorder2.size() - 1, postIndex2);

    cout << "Test Case 2:\n";
    cout << "Inorder Traversal: ";
    printInorder(root2);
    cout << "\nPostorder Traversal: ";
    printPostorder(root2);
    cout << "\nLevel Order Traversal:\n";
    printLevelOrder(root2);
    cout << endl;

    return 0;
}