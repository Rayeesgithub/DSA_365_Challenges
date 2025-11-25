#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to insert a node right at the head of Linked List
void insertAtHead(Node*& head, Node*& tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    } else {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

// Function to insert a node right at the end of Linked List
void insertAtTail(Node*& head, Node*& tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void print(Node* head) {

        Node* temp = head;
        while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
        }
        cout<<endl;
}

// Function to find total number of nodes in Linked List
int findLength(Node* &head) {
    int len = 0;              // Length counter
    Node* temp = head;        // Pointer to traverse list

    while(temp != NULL) {     // Loop until end of list
        temp = temp->next;    // Move to next node
        len++;                // Count increment
    }
    return len;               // Return final count
}


// Insert node at a specific position in the Linked List
void insertAtPosition(int data, int position, Node* &head, Node* &tail) {

    // CASE 1️⃣: If list is empty
    if(head == NULL) {
        Node* newNode = new Node(data); // Create node
        head = newNode;                 // Set head and tail to same node
        tail = newNode;
        return;
    }

    // CASE 2️⃣: Insert at position = 0 → means insert at head
    if(position == 0) {
        insertAtHead(head, tail, data); // Already created function
        return;
    }

    // Find total nodes in list
    int len = findLength(head);

    // CASE 3️⃣: If position is >= length → insert at tail (end)
    if(position >= len) {
        insertAtTail(head, tail, data);
        return;
    }


    // CASE 4️⃣: Insert in the middle (valid index inside list)

    // Step 1: Move `prev` to node just before the insertion point
    int i = 1;
    Node* prev = head;
    while(i < position) {     // Stop one step before target index
        prev = prev->next;
        i++;
    }

    Node* curr = prev->next;  // Node currently at the target position

    // Step 2: Create new node
    Node* newNode = new Node(data);

    // Step 3: Link new node to current node
    newNode->next = curr;

    // Step 4: Link previous node to new node
    prev->next = newNode;
}


int main() {

        Node* head = NULL;
    Node* tail = NULL;

    int choice, data, position;
    while (true) {
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Print List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at head: ";
                cin >> data;
                insertAtHead(head, tail, data);
                break;
            case 2:
                cout << "Enter data to insert at tail: ";
                cin >> data;
                insertAtTail(head, tail, data);
                break;
            case 3:
                cout << "Enter position to insert: ";
                cin >> position;
                cout << "Enter data to insert: ";
                cin >> data;
                insertAtPosition(data, position, head, tail);
                break;
            case 4:
                print(head);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
