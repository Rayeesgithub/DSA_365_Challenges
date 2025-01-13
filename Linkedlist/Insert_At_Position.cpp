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

int findLength(Node* &head ) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp->next;
                len++;
        }
        return len;
}

void insertAtPosition(int data, int position, Node* &head, Node* &tail) {
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                return;
        }
        //step1: find the position: prev & curr;

        if(position == 0) {
                insertAtHead(head, tail , data);
                return;
        }
       
        int len = findLength(head);
        
        if(position >= len) {
                insertAtTail(head, tail, data);
                return;
        }
        //ste1:find prev and curr
        int i = 1;
        Node* prev = head;
        while(i < position) {
                prev= prev -> next;
                i++;
        }
        Node* curr = prev -> next;

        //step2;
        Node* newNode = new Node(data);

        //step3:
        newNode -> next = curr;

        //step4:
        prev -> next = newNode;
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
