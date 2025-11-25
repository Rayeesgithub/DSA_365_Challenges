// Love Babbar
    bool isCircular(Node *head) {

        // If the list is empty, we consider it circular
        // because it does not break the circular condition.
        if(head == NULL) 
            return true;

        // Start from the node next to head
        Node* curr = head->next;

        // Traverse the list
        // Stop when:
        // 1) curr becomes NULL  → list is not circular
        // 2) curr becomes head  → list is circular
        while(curr != head && curr != NULL) {
            curr = curr->next;  // move to next node
        }

        // If curr == head, we came back to start → Circular list
        if(curr == head) {
            return true;
        }

        // Otherwise curr became NULL → Not circular
        return false;
}
