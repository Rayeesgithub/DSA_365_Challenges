#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* next; // Used for linked list

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

// Function to convert a sorted linked list to a BST
Node* sortedToLL(Node*& head, int n) {
    if (head == NULL || n <= 0) { // Base case
        return NULL;
    }

    // Recursively create left subtree
    Node* leftSubtree = sortedToLL(head, n / 2);

    // Create root node with current head
    Node* root = head;

    // Move head to the next node in the linked list
    head = head->next;

    // Attach left subtree to root
    root->left = leftSubtree;

    // Recursively create right subtree
    root->right = sortedToLL(head, n - 1 - n / 2);

    return root;
}

// Function to construct a linked list
Node* createLinkedList(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < arr.size(); i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

// Function for level-order traversal
void LevelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL) {
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
}

int main() {
    // Input sorted array
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    // Convert array to linked list
    Node* head = createLinkedList(arr);

    // Convert sorted linked list to BST
    Node* root = sortedToLL(head, arr.size());

    // Perform level-order traversal
    cout << "Level order Traversal is: ";
    LevelOrderTraversal(root);

    return 0;
}
