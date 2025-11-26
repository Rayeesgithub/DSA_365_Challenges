//striver sheet
https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1


Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2

//approach1 (Broute force)

 Node* segregate(Node *head) {

    // We are given a linked list containing only 0s, 1s, and 2s.
    // Goal: Rearrange nodes so that all 0s come first, then 1s, then 2s.
    // APPROACH: Count how many 0,1,2 exist → then rewrite node values.

    int zerocount = 0;  
    int onecount = 0;   
    int twocount = 0;

    Node* temp = head;

    // Step 1: Count how many 0s, 1s, 2s are present
    while(temp != NULL) {

        if(temp->data == 0) {
            zerocount++;
        }
        else if(temp->data == 1) {
            onecount++;
        }
        else { 
            twocount++;
        }

        temp = temp->next;   // move to next node
    }

    // Step 2: Rewrite the linked list data in sorted order
    temp = head;

    // Write all 0s first
    while(zerocount--) {
        temp->data = 0;
        temp = temp->next;
    }

    // Then write all 1s
    while(onecount--) {
        temp->data = 1;
        temp = temp->next;
    }

    // Finally write all 2s
    while(twocount--) {
        temp->data = 2;
        temp = temp->next;
    }

    return head;  // return updated head
}



// 2nd approach
  Node* segregate(Node* head) {

    // Dummy heads for 0s, 1s, and 2s lists
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    // Step 1: Separate the nodes into 3 lists
    Node* temp = head;

    while (temp != NULL) {

        if (temp->data == 0) { 
            zeroTail->next = temp;
            zeroTail = zeroTail->next;
        }
        else if (temp->data == 1) {
            oneTail->next = temp;
            oneTail = oneTail->next;
        }
        else { // temp->data == 2
            twoTail->next = temp;
            twoTail = twoTail->next;
        }

        temp = temp->next;  // move ahead
    }

    // Step 2: Connect the three lists in order 0 → 1 → 2
    // If 1-list exists, join 0-list to it, else join directly to 2-list
    zeroTail->next = (oneHead->next != NULL) ? oneHead->next : twoHead->next;

    // Join 1-list to 2-list
    oneTail->next = twoHead->next;

    // Last list ends with NULL
    twoTail->next = NULL;

    // Final head starts after dummy zeroHead
    Node* newHead = zeroHead->next;

    // Delete dummy nodes (no longer needed)
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;   // ❗ return new head, not original "head"
}
