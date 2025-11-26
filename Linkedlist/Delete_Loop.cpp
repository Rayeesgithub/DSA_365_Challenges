Input:
1 → 2 → 3 → 4 → 5
          ↑     |
          |_____|

Cycle starts at node 3
o/p->  1 → 2 → 3 → 4 → 5 → NULL

ListNode *detectCycle(ListNode *head) {

    if(head == NULL) return NULL;

    ListNode* slow = head;
    ListNode* fast = head;

    // STEP 1: Detect cycle
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {   // cycle detected
            slow = head;
            break;
        }
    }

    // NO CYCLE CASE
    if(fast == NULL || fast->next == NULL) {
        return NULL;
    }

    // STEP 2: Find cycle start + node before start
    ListNode* prev = fast;   // prev will track the node just before fast
    
    while(slow != fast) {
        slow = slow->next;
        prev = fast;          // update prev before moving fast
        fast = fast->next;
    }

    // Now slow == fast = start of loop
    // prev is the last node inside the loop
    prev->next = NULL;   // remove loop safely

    return slow;         // return cycle start (optional)
}
