#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;         // Data stored in the node
    Node* next;       // Pointer to the next node

    Node(int data) {  // Constructor for creating a node
        this->data = data;  // Initialise the data member
        this->next = nullptr;  // Initialise the next pointer to nullptr
    }
};

// Define the LinkedList class
class LinkedList {
private:
    Node* head;  // Pointer to the first node in the list

public:
    LinkedList() {
        head = nullptr;  // Constructor: Initialise the head pointer to nullptr (empty list)
    }

    // Function to add a new node at the end of the list
    void append(int data) {
        Node* newNode = new Node(data);  // Create a new node with the given data
        if (head == nullptr) {  // If the list is empty
            head = newNode;  // Set the head to the new node
        } else {  // If the list is not empty
            Node* temp = head;  // Create a temporary pointer starting from the head
            while (temp->next != nullptr) {  // Traverse the list to find the last node
                temp = temp->next;
            }
            temp->next = newNode;  // Link the last node's next pointer to the new node
        }
    }

    // Function to print the linked list
    void print() {
        Node* temp = head;  // Create a temporary pointer starting from the head
        while (temp != nullptr) {  // Traverse the list
            cout << temp->data << " -> ";  // Print the data of the current node
            temp = temp->next;  // Move to the next node
        }
        cout << "NULL" << endl;  // Print "NULL" to indicate the end of the list
    }

    // Function to delete a node by value
    void deleteByValue(int value) {
        if (head == nullptr) return;  // If the list is empty, nothing to delete

        if (head->data == value) {  // If the node to delete is the head
            Node* temp = head;  // Create a temporary pointer to the head
            head = head->next;  // Update the head to point to the next node
            delete temp;  // Delete the old head node
            return;
        }

        Node* current = head;  // Create a pointer to traverse the list, starting from the head
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;  // Traverse the list to find the node to delete
        }

        if (current->next != nullptr) {  // If the node to delete is found
            Node* temp = current->next;  // Create a temporary pointer to the node to delete
            current->next = current->next->next;  // Update the next pointer to skip the node
            delete temp;  // Delete the node
        }
    }

    // Destructor to clean up the list
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
    list.append(1);  // Add elements to the list
    list.append(2);
    list.append(3);
    list.print();  // Print the list (should print: 1 -> 2 -> 3 -> NULL)

    list.deleteByValue(2);  // Delete a node by value
    list.print();  // Print the updated list (should print: 1 -> 3 -> NULL)

    return 0;  // Exit the program
}
