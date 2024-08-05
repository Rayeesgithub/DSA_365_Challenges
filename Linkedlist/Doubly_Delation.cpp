//striver sheet
#include<iostream>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Default constructor
    Node() {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }

    // Parameterized constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to print the linked list
void print(Node* &head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to find the length of the linked list
int findLength(Node* &head) {
    Node* temp = head;
    int len = 0;
    while(temp != nullptr) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Function to insert a node at the head of the linked list
void insertAtHead(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Function to delete a node at a given position in the linked list
void DelationPos(Node* &head, Node* &tail, int position) {
    // Case: Deleting the head node
    if(position == 1) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = findLength(head);

    // Case: Deleting the tail node
    if(position >= len) {
        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;
        return;
    }

    // Case: Deleting a node in the middle
    int i = 1;
    Node* left = head;
    while(i < position - 1) {
        left = left->next;
        i++;
    }
    Node* curr = left->next;
    Node* right = curr->next;

    left->next = right;
    right->prev = left;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}

// Main function to test the linked list operations
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Inserting nodes at the head
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40
