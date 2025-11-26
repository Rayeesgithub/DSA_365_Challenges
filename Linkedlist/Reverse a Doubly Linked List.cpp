Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

// striver sheet
  Node* reverseDLL(Node * head)
    {
        
    Node* prev = NULL;   
    Node* curr = head;    

     while (curr != NULL) {
        // Step 1: Store the next node
        Node* forward = curr->next;

        // Step 2: Reverse the current node's next and prev pointers
        curr->next = prev;
        curr->prev = forward;

        // Step 3: Move the prev pointer to the current node
        prev = curr;

        // Step 4: Move the curr pointer to the next node in the original list
        curr = forward;
    }
    
    // At the end of the loop, prev will be pointing to the new head of the reversed list
    return prev;
    }
