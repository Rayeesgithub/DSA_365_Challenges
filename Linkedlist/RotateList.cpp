Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

  Dry Run->
  Step 1 → Count Length
     len = 5,   temp is at last node = 5
 Step 2 → Make List Circular
1 → 2 → 3 → 4 → 5
↑               ↓
← ← ← ← ← ← ← ← ←

  Step 3 → Effective k
k = k % len = 2 % 5 = 2
Find point to break
stepsToNewHead = len - k = 5 - 2 = 3
This means we move 3 steps from last node (5).

  Step 4 → Move temp to node before new head
Current temp = 5
We need to move 3 steps.
Now temp is at node 3 (the node before new head).

  Step 5 → Break the circle
temp->next = NULL     // 3->next = NULL
4 → 5 → 1 → 2 → 3 → NULL




  

ListNode* rotateRight(ListNode* head, int k) {

    // If list is empty or has one node → no rotation needed
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    // Step 1: Find length of list
    int len = 1;
    ListNode* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
        len++;
    }

    // Step 2: Connect last node to head → make it circular
    temp->next = head;

    // Step 3: Effective rotations
    k = k % len;        // If k >= len
    int stepsToNewHead = len - k;  

    // Step 4: Move temp to node just before new head
    while(stepsToNewHead--) {
        temp = temp->next;
    }

    // Step 5: Set new head and break the circle
    head = temp->next;
    temp->next = NULL;

    return head;
}
