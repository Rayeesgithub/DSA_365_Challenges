#include <bits/stdc++.h>
using namespace std;

// Node class to represent each element of Linked List
class Node {
public:
    int data;      // stores value
    Node* next;    // stores address of next node
    
    // Constructor: initialize data and next pointer
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert new node at Head (Beginning of Linked List)
void InsertAtHead(Node* &head, Node* &tail, int data) {
    // If list is empty
    if (head == NULL) {
        Node* newNode = new Node(data); // create new node
        head = newNode;                 // both head and tail will point to this node
        tail = newNode;
        return;                          // exit function
    }

    // If list already has elements
    Node* newNode = new Node(data); // create new node
    newNode->next = head;          // link new node to previous head
    head = newNode;                // move head to new node
}

// Function to print Linked List
void print(Node* head) {
    Node* temp = head;  // start from head
    while (temp != NULL) { 
        cout << temp->data << " -> "; // print data
        temp = temp->next;            // move to next node
    }
    cout << "NULL" << endl;  // end of list
}

int main() {
    Node* head = NULL; // Initially list is empty
    Node* tail = NULL; // tail also NULL

    InsertAtHead(head, tail, 30); // List: 30
    InsertAtHead(head, tail, 20); // List: 20 -> 30
    InsertAtHead(head, tail, 10); // List: 10 -> 20 -> 30

    print(head); // Print list

    return 0;
}
