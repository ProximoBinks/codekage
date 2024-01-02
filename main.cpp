#include <iostream>
using namespace std;

// Node structure for a single linked list
struct Node{
    int data; // Integer data held by the node
    Node * next; // Pointer to the next node in the list
    // Constructor initializes the node with given data and sets next to nullptr
    Node(int d) : data(d), next(nullptr) {}
};

// LinkedList class defines a singly linked list
class LinkedList{
public:
    Node* head; // Pointer to the first node in the list

    // Constructor initializes an empty linked list with head pointing to nullptr
    LinkedList() : head(nullptr) {}

    // Function to add a new node with given data at the front of the list
    void addFront(int data) {
        Node* newNode = new Node(data); // Create a new node with given data
        newNode->next = head; // New node points to the current head
        head = newNode; // New node becomes the new head
    }

    // Function to display the contents of the list
    void display() {
        Node* current = head; // Start from the head of the list
        while (current != nullptr) { // Traverse until the end of the list
            cout << current->data << " -> "; // Print the data of the current node
            current = current->next; // Move to the next node
        }
        cout << "NULL" << endl; // Indicate the end of the list
    }

    // Destructor to free the memory used by the list
    ~LinkedList() {
        while (head != nullptr) { // Traverse the list
            Node* temp = head; // Hold the current node
            head = head->next; // Move the head to the next node
            delete temp; // Delete the old head node
        }
    }
};

int main() {
    LinkedList list; // Create a new linked list
    list.addFront(3); // Add elements to the list
    list.addFront(2);
    list.addFront(1);

    cout << "Linked List: ";
    list.display(); // Display the contents of the list

    return 0; // End of the program
}
