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

    void insert(int data) {
        root = insertRec(root, data);
    }

    Node* deleteNode(Node* root, int data) {
        if (root == nullptr) return root;
        if (data < root->data)
            root->left = deleteNode(root->left, data);
        else if (data > root->data)
            root->right = deleteNode(root->right, data);
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
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
    Node* insertRec(Node* root, int data) {
        if (root == nullptr) {
            return new Node(data);
        }
        if (data < root->data) {
            root->left = insertRec(root->left, data);
        } else {
            root->right = insertRec(root->right, data);
        }
        return root;
    }

    void inorderRec(Node* root) {
        if (root != nullptr) {
            inorderRec(root->left);
            cout << root->data << " ";
            inorderRec(root->right);
        }
    }

    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
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