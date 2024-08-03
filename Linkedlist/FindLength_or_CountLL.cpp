//striver sheet
https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-nodes-of-linked-list


#include <iostream>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to count the number of nodes in a linked list
int getCount(struct Node* head) {
    int len = 0;  // Initialize a variable to store the length of the list
    Node* temp = head;  // Start from the head of the list

    // Traverse the list until the end (NULL) is reached
    while (temp != nullptr) {
        temp = temp->next;  // Move to the next node
        len++;  // Increment the count for each node encountered
    }

    return len;  // Return the total count of nodes in the list
}

int main() {
    // Create a linked list with some nodes
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Get the count of nodes in the list
    int count = getCount(head);

    // Print the count
    cout << "The number of nodes in the linked list is: " << count << endl;

    return 0;
}
