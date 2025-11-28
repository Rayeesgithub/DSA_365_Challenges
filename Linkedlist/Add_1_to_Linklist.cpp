Input: LinkedList: 4->5->6
Output: 456+1=457

  
  // Function to reverse a linked list
Node* reverseList(Node* &head) {

    Node* prev = NULL;     // Previous pointer (initially NULL)
    Node* curr = head;     // Current pointer starts from head

    // Traverse the list and reverse links
    while (curr) {
        Node* forward = curr->next;  // Store next node
        curr->next = prev;           // Reverse the pointer
        prev = curr;                 // Move prev forward
        curr = forward;              // Move curr forward
    }

    return prev;     // New head of the reversed list
}



// Function to add 1 to the number represented by linked list
Node* addOne(Node* head) {

    // Step 1: Reverse the list (so we start adding from least significant digit)
    head = reverseList(head);

    int carry = 1;         // We want to add 1, so carry = 1 initially
    Node* curr = head;

    // Step 2: Traverse list and add the carry
    while (curr != NULL && carry) {

        int sum = curr->data + carry;  // Add carry to current digit
        curr->data = sum % 10;         // Store the last digit in current node
        carry = sum / 10;              // Update carry

        // If it's the last node and still carry remains → create a new node
        if (!curr->next && carry) {
            curr->next = new Node(carry);  
            carry = 0;                 // After adding new node, no more carry
        }

        curr = curr->next;             // Move to the next node
    }

    // Step 3: Reverse again to restore original order
    head = reverseList(head);

    return head;  // Final result list
}
