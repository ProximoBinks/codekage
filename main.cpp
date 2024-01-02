#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
public:
    Node *head;
    LinkedList() : head(nullptr) {}

    void addFront(int data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Function to delete a node with a specific value
    void deleteNode(int value) {
        Node *temp = head, *prev = nullptr;
        // If head node itself holds the key to be deleted
        if (temp != nullptr && temp->data == value) {
            head = temp->next; // Changed head
            delete temp;       // free old head
            return;
        }
        // Search for the key to be deleted
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }
        // If key was not present in linked list
        if (temp == nullptr) return;
        // Unlink the node from linked list
        prev->next = temp->next;
        delete temp; // Free memory
    }

    void display() {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    list.addFront(3);
    list.addFront(2);
    list.addFront(1);
    cout << "Linked List before deletion: ";
    list.display();
    list.deleteNode(2); // Delete node with value 2
    cout << "Linked List after deletion: ";
    list.display();
    return 0;
}