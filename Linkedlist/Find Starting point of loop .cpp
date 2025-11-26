Input Linked List:
1 → 2 → 3 → 4 → 5
          ↑     |
          |_____|

pos = 2   (cycle starts at node with value 3)

Step 1: Detect cycle using slow/fast

slow at 1, fast at 1
slow at 2, fast at 3
slow at 3, fast at 5
slow at 4, fast at 4 → 🎉 slow == fast → cycle detected

Step 2: Move slow to head
slow = 1, fast = 4
Move both one step at a time:
slow: 1 → 2 → 3
fast: 4 → 5 → 3

They meet at node 3 → cycle start.
✔️ Output: Node with value 3


Input: head = [1], pos = -1

Linked List:
1 → NULL




ListNode *detectCycle(ListNode *head) {

    // If list is empty → no cycle
    if(head == NULL) return NULL;

    // Two pointers: slow moves 1 step, fast moves 2 steps
    ListNode* slow = head;
    ListNode* fast = head;

    // -------- STEP 1: Detect if a cycle exists -------- //
    while(fast != NULL && fast->next != NULL) {

        slow = slow->next;           // slow moves one step
        fast = fast->next->next;     // fast moves two steps

        // If they meet → cycle exists
        if(slow == fast) {
            // Move slow back to head to find cycle start
            slow = head;
            break;
        }
    }

    // -------- NO CYCLE CASE -------- //
    // If fast reaches NULL → no cycle is present
    if(fast == NULL || fast->next == NULL) {
        return NULL;
    }

    // -------- STEP 2: Find the starting node of the cycle -------- //
    // Now move slow and fast one step at a time
    // They will meet exactly at the cycle start point
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // slow (or fast) now points at the cycle's start node
    return slow;
}
