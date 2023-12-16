#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
    Node(int d) : data(d), next(nullptr) {}

};

class LinkedList{
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void addFront(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
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

    cout << "Linked List: ";
    list.display();

    return 0;
}