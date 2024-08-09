//striver sheet
https://www.geeksforgeeks.org/problems/introduction-to-linked-list/0

Time Complexity: O(n) && Auxiliary Space: O(n)
  
  Node* constructLL(vector<int>& arr) {
    // Initialize the head node with the first element of the array
    Node* head = new Node(arr[0]);

    // Initialize the current pointer to keep track of the current node
    Node* current = head;

    // Loop through the array starting from the second element
    for (auto i = 1; i < arr.size(); ++i) {
        // Create a new node for the current element and link it to the next pointer of the current node
        current->next = new Node(arr[i]);
        
        // Move the current pointer to the newly created node
        current = current->next;
    }

    // Return the head of the constructed linked list
    return head;
}
