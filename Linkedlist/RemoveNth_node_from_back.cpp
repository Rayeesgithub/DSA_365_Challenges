
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]


ListNode* removeNthFromEnd(ListNode* head, int n) {

    // Create dummy node to simplify edge cases (deleting 1st node)
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;

    // slow & fast both start at dummy
    ListNode* slow = dummy;
    ListNode* fast = dummy;

    // Move fast pointer n+1 steps ahead
    // So the gap between slow and fast becomes n nodes
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both pointers until fast reaches null
    // Now slow will be just before the node to delete
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // slow → node before the node to delete
    ListNode* delNode = slow->next;  // node to delete

    // Remove delNode from the list
    slow->next = slow->next->next;

    delete delNode;   // free memory

    // Return updated head (dummy->next)
    return dummy->next;
}
