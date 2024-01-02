#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    // Function to insert data into the tree
    void insert(int data) {
        root = insertRec(root, data);
    }

    // Function to delete a node with a specific value from the tree
    Node* deleteNode(Node* root, int data) {
        if (root == nullptr) return root; // Base case: tree is empty
        // Recursively find the node to delete
        if (data < root->data)
            root->left = deleteNode(root->left, data);
        else if (data > root->data)
            root->right = deleteNode(root->right, data);
        else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);
            root->data = temp->data; // Copy the inorder successor's content to this node
            root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
        }
        return root;
    }

    void inorder() {
        inorderRec(root);
    }

    ~BinaryTree() {
        destroyTree(root);
    }

private:
    // Helper functions for insert, delete, and inorder traversal
    Node* insertRec(Node* root, int data);
    void inorderRec(Node* root);
    void destroyTree(Node* node);
    Node* minValueNode(Node* node);
};

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "Inorder Traversal before deletion: ";
    tree.inorder();
    cout << endl;

    tree.deleteNode(tree.root, 3); // Delete node with value 3
    cout << "Inorder Traversal after deletion: ";
    tree.inorder();
    cout << endl;

    return 0;
}