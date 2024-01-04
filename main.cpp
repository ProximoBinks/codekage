#include <iostream>
using namespace std;

// Node structure for Binary Tree
struct Node {
    int data;         // Data stored in the node
    Node* left;       // Pointer to the left child node
    Node* right;      // Pointer to the right child node

    Node(int data) : data(data), left(nullptr), right(nullptr) {}  // Constructor for initializing a node
};

// BinaryTree class
class BinaryTree {
private:
    Node* root;  // Pointer to the root node of the binary tree

    // Helper function to insert data in the binary tree
    Node* insert(Node* node, int data) {
        if (node == nullptr) {  // If the current node is nullptr
            return new Node(data);  // Create a new node with the given data
        }
        if (data < node->data) {  // If the data is less than the current node's data
            node->left = insert(node->left, data);  // Recursively insert in the left subtree
        } else if (data > node->data) {  // If the data is greater than the current node's data
            node->right = insert(node->right, data);  // Recursively insert in the right subtree
        }
        return node;  // Return the updated node
    }

    // Helper function for in-order traversal of the tree
    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);  // Recursively traverse the left subtree
            cout << node->data << " ";  // Print the data of the current node
            inOrder(node->right);  // Recursively traverse the right subtree
        }
    }

    // Helper function for pre-order traversal of the tree
    void preOrder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";  // Visit the root
            preOrder(node->left);      // Traverse the left subtree
            preOrder(node->right);     // Traverse the right subtree
        }
    }

    // Helper function for post-order traversal of the tree
    void postOrder(Node* node) {
        if (node != nullptr) {
            postOrder(node->left);     // Traverse the left subtree
            postOrder(node->right);    // Traverse the right subtree
            cout << node->data << " "; // Visit the root
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int data) {
        root = insert(root, data);  // Call the private insert method
    }

    void inOrderTraversal() {
        inOrder(root);
        cout << endl;
    }

    // Function for pre-order traversal
    void preOrderTraversal() {
        preOrder(root);
        cout << endl;
    }

    // Function for post-order traversal
    void postOrderTraversal() {
        postOrder(root);
        cout << endl;
    }

    ~BinaryTree() {
        deleteTree(root);
    }

    // Helper function for destructor to deallocate memory
    void deleteTree(Node* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }
};

// Main Function
int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "In-order Traversal: ";
    tree.inOrderTraversal();

    cout << "Pre-order Traversal: ";
    tree.preOrderTraversal();

    cout << "Post-order Traversal: ";
    tree.postOrderTraversal();

    return 0;
}
