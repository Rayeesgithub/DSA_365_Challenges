// basic love babbar

why we need consructor function
 Node(int value) {
        this->data = value;
        this->next = nullptr;
    }
Answer->  
    Example using constructor: Node* newNode = new Node(10);
    Example without constructor: We would need to write extra lines every time:
      Node* newNode = new Node;
      newNode->data = 10;
      newNode->next = nullptr;





#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
      
    Node(int value) {
        this->data = value;
        this->next = nullptr;
    }
};

// Function to print Linked List
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    // Creating nodes
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    // Linking nodes
    head->next = second;
    second->next = third;

    // Printing Linked List
    cout << "Linked List: ";
    printList(head);

    return 0;
}
