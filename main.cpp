#include <iostream>
using namespace std;

// Node structure for a Binary Tree
struct Node {
    int data; // Integer data held by the node
    Node* left; // Pointer to the left child node
    Node* right; // Pointer to the right child node

    // Constructor initializes the node with given data and null child pointers
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

// BinaryTree class defines a binary search tree
class BinaryTree {
public:
    Node* root; // Pointer to the root node of the tree

    // Constructor initializes an empty tree with root pointing to nullptr
    BinaryTree() : root(nullptr) {}

    // Public function to insert data into the tree
    void insert(int data) {
        root = insertRec(root, data);
    }

    // Public function for inorder traversal of the tree
    void inorder() {
        inorderRec(root);
    }

    // Destructor to free the memory used by the tree
    ~BinaryTree() {
        destroyTree(root);
    }

private:
    // Private recursive function to insert data at the appropriate position in the tree
    Node* insertRec(Node* root, int data) {
        if(root == nullptr) { // If the tree/subtree is empty, create a new node
            return new Node(data);
        }
        // Recursively insert into the left or right subtree based on the data's value
        if (data < root->data) {
            root->left = insertRec(root->left, data);
        } else {
            root->right = insertRec(root->right, data);
        }
        return root;
    }

    // Private recursive function for inorder traversal of the tree
    void inorderRec(Node* root) {
        if (root != nullptr) { // If the current node is not null
            inorderRec(root->left); // Recursively visit the left subtree
            cout << root->data << " "; // Visit the current node
            inorderRec(root->right); // Recursively visit the right subtree
        }
    }

    // Private function to destroy the tree and free memory
    void destroyTree(Node* node) {
        if (node != nullptr) { // If the current node is not null
            destroyTree(node->left); // Recursively destroy the left subtree
            destroyTree(node->right); // Recursively destroy the right subtree
            delete node; // Delete the current node
        }
    }
};

int main() {
    BinaryTree tree; // Create a new binary tree
    // Insert elements into the tree
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "Inorder Traversal: ";
    tree.inorder(); // Perform an inorder traversal and print the elements
    cout << endl;

    return 0; // End of the program
}