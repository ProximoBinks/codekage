#include <iostream>
using namespace std;

// Define the Node structure for a doubly linked list
struct Node {
    int data;          // Data stored in the node
    Node* next;        // Pointer to the next node
    Node* prev;        // Pointer to the previous node

    // Constructor for creating a node
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

// Define the LinkedList class
class LinkedList {
private:
    Node* head;  // Pointer to the first node in the list
    Node* tail;  // Pointer to the last node in the list

public:
    // Constructor: Initialise the head and tail pointers to nullptr (empty list)
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Function to add a new node at the beginning of the list
    // Time Complexity: O(1)
    void insert(int data) {
        Node* newNode = new Node(data);  // Create a new node with the given data

        newNode->next = head;  // Set the new node's next pointer to the current head

        if (head != nullptr) {  // If the list is not empty
            head->prev = newNode;  // Set the current head's previous pointer to the new node
        } else {  // If the list is empty
            tail = newNode;  // Set the tail to the new node
        }

        head = newNode;  // Update the head to the new node
        newNode->prev = nullptr;  // Set the new node's previous pointer to nullptr
    }

    // Function to delete a node by value
    // Time Complexity: O(n) - in the worst case, we might need to traverse the entire list
    void deleteByValue(int value) {
        Node* current = head;  // Create a pointer to traverse the list, starting from the head

        while (current != nullptr && current->data != value) {
            current = current->next;  // Traverse the list to find the node to delete
        }

        if (current == nullptr) return;  // If the node was not found, nothing to delete

        if (current->prev != nullptr) {
            current->prev->next = current->next;  // Link previous node to the next node
        } else {
            head = current->next;  // If deleting the head, update the head pointer
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;  // Link next node to the previous node
        } else {
            tail = current->prev;  // If deleting the tail, update the tail pointer
        }

        delete current;  // Delete the node
    }

    // Function to print the linked list
    // Time Complexity: O(n) - needs to traverse the entire list to print all elements
    void print() {
        Node* temp = head;  // Create a temporary pointer starting from the head
        while (temp != nullptr) {  // Traverse the list
            cout << temp->data << " -> ";  // Print the data of the current node
            temp = temp->next;  // Move to the next node
        }
        cout << "NULL" << endl;  // Print "NULL" to indicate the end of the list
    }

    // Search function (O(n))
    Node* search(int value) {
        Node* current = head;  // Start from the head of the list
        while (current != nullptr) {  // Traverse the list
            if (current->data == value) {  // If the node with the desired value is found
                return current;  // Return a pointer to the node
            }
            current = current->next;  // Move to the next node
        }
        return nullptr;  // If the value is not found in the list, return nullptr
    }

    // Destructor to clean up the list
    // Time Complexity: O(n) - needs to delete all nodes one by one
    ~LinkedList() {
        while (head != nullptr) {  // Iterate through the list
            Node* temp = head;  // Create a temporary pointer to the head
            head = head->next;  // Move the head to the next node
            delete temp;  // Delete the current node
        }
    }
};

// Main function to demonstrate the LinkedList operations
int main() {
    LinkedList list;  // Create a linked list object
    list.insert(3);  // Add elements to the list
    list.insert(2);
    list.insert(1);
    list.print();  // Print the list (should print: 1 -> 2 -> 3 -> NULL)

    Node* foundNode = list.search(2);  // Search for the value 2 in the list
    if (foundNode != nullptr) {
        cout << "Found node with value: " << foundNode->data << endl;
    } else {
        cout << "Value not found in the list." << endl;
    }

    list.deleteByValue(2);  // Delete a node by value
    cout << "Deleted 2" << endl;
    list.print();  // Print the updated list (should print: 1 -> 3 -> NULL)

    Node* foundNode2 = list.search(2);  // Search for the value 2 in the list again
    if (foundNode2 != nullptr) {
        cout << "Found node with value: " << foundNode2->data << endl;
    } else {
        cout << "Value not found in the list." << endl;
    }

    return 0;  // Exit the program
}