https://leetcode.com/problems/reverse-linked-list/description/

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

✅ total time = O(n) && space = O(n)
ListNode* solve(ListNode* &prev, ListNode* &curr) {
    
    // BASE CASE:
    // If current node becomes NULL, we have reached the end.
    // At this moment, prev is the NEW HEAD of reversed list.
    if(curr == NULL) 
        return prev;

    // Store next node before breaking the link
    ListNode* forward = curr->next;

    // Reverse the link: point current node backward
    curr->next = prev;

    // Recursive call with:
    // prev  = curr
    // curr  = forward (next node)
    return solve(curr, forward);
}

// Wrapper function that sets up initial values
ListNode* reverseList(ListNode* head) {

    ListNode* prev = NULL;   // Start of reversed list will be NULL initially
    ListNode* curr = head;   // Start from head

    // Call recursive function
    return solve(prev, curr);
}



Dry RUN_> 1 → 2 → 3 → NULL
    CALL1:
    prev = NULL
curr = 1
forward = 2
1->next = NULL
call solve(1, 2)

    CALL2:
    prev = 1
curr = 2
forward = 3
2->next = 1
call solve(2, 3)

Call3:
prev = 2
curr = 3
forward = NULL
3->next = 2
call solve(3, NULL)

Call4:
curr == NULL
return prev (which is 3)

    final reverse-> 3,2,1,NULL

    ✅ time:0(n) space=(1)
ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;   // Pointer to store previous node (starts as NULL)
        ListNode* curr = head;   // Pointer to current node

        // Loop until we reach the end of the list
        while(curr != NULL) {

            // Save the next node before breaking the link
            ListNode* forward = curr->next;

            // Reverse the link: current node points to previous node
            curr->next = prev;

            // Move prev forward
            prev = curr;

            // Move curr forward
            curr = forward;
        }

        // prev now becomes the new head of the reversed list
        return prev;
}
