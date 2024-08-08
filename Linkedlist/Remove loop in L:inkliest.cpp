// Love babbar
      
    if (head == NULL || head->next == NULL) {
        return;
    }
    
    Node* slow = head;
    Node* fast = head;

    // Detecting the loop using Floyd’s Cycle-Finding Algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet, there is a loop
        if (slow == fast) {
            break;
        }
    }

    // No loop detected
    if (slow != fast) {
        return;
    }

    // If loop is detected, move slow to head and keep fast at the meeting point
    slow = head;

    // If the loop is connected to the head itself
    if (slow == fast) {
        // Traverse to the last node in the loop
        while (fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;
    } else {
        // Move both pointers one step at a time to find the start of the loop
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        // Break the loop
        fast->next = NULL;
    }  
    }
