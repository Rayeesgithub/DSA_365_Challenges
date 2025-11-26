Input List
1 → 2 → 3 → 4 → 5
          ↑     |
          |_____|
Cycle Nodes: 3 → 4 → 5 → 3
Loop Length = 3
  
slow = fast meet at node 4
start counting:
4→5→3→4
count = 3




int lengthOfLoop(Node *head) {

    if(head == NULL) return 0;

    Node* slow = head;
    Node* fast = head;

    // -------- STEP 1: Detect the cycle --------
    while(fast != NULL && fast->next != NULL) {

        slow = slow->next;       // slow moves 1 step
        fast = fast->next->next; // fast moves 2 steps

        if(slow == fast) {       // meeting point found → loop exists

            // -------- STEP 2: Count loop length --------
            int count = 1;
            fast = fast->next;   // move fast one step

            while(fast != slow) { // keep moving until loop completes
                fast = fast->next;
                count++;
            }

            return count;        // return total loop length
        }
    }

    return 0; // no cycle in the list
}
