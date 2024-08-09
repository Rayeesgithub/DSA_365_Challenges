// striver sheet
//
// Function to construct a doubly linked list from a vector
Node* constructDLL(vector<int>& arr) {
    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    Node* current = head;

    // Iterate through the rest of the array to create nodes
    for (int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);
        current->next = newNode; // Link current node's next to new node
        newNode->prev = current; // Link new node's prev to current node
        current = newNode; // Move current to the new node
    }

    return head; // Return the head of the doubly linked list
}
