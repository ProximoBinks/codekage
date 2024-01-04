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

public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Function to insert data
    void insert(int data) {
        root = insert(root, data);  // Call the private insert method
    }

    // Function for in-order traversal
    void inOrderTraversal() {
        inOrder(root);  // Call the private inOrder method to perform in-order traversal
        cout << endl;  // Print a newline to separate the output
    }

    // Destructor to deallocate memory
    ~BinaryTree() {
        deleteTree(root);  // Call the private deleteTree method
    }

    // Helper function for destructor to deallocate memory
    void deleteTree(Node* node) {
        if (node != nullptr) {
            deleteTree(node->left);   // Recursively delete the left subtree
            deleteTree(node->right);  // Recursively delete the right subtree
            delete node;  // Delete the current node
        }
    }
};

// Main Function
int main() {
    BinaryTree tree;  // Create a binary tree object
    tree.insert(5);   // Insert data into the tree
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "In-order Traversal: ";
    tree.inOrderTraversal();  // Perform in-order traversal and print the result

    return 0;  // Exit the program
}