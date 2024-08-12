//striver sheet
https://leetcode.com/problems/merge-two-sorted-lists/description/


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // Create a dummy node to serve as the starting point for the merged list.
    // The actual merged list will start from ans->next.
    ListNode* ans = new ListNode(-1);
    
    // Pointer to build the merged list. It starts at the dummy node.
    ListNode* ptr = ans;

    // Edge cases: if one of the lists is empty, return the other list.
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    // Iterate through both lists while both are non-empty.
    while(list1 != NULL && list2 != NULL) {
        // Compare the values at the current nodes of both lists.
        if(list1->val <= list2->val) {
            // If list1's value is smaller or equal, append list1's node to the merged list.
            ptr->next = list1;
            
            // Move the pointer in the merged list and list1 forward.
            ptr = list1;
            list1 = list1->next;
        }
        else if(list1->val > list2->val) {
            // If list2's value is smaller, append list2's node to the merged list.
            ptr->next = list2;
            
            // Move the pointer in the merged list and list2 forward.
            ptr = list2;
            list2 = list2->next;
        }
    }

    // If any nodes remain in list1, append them to the merged list.
    while(list1 != NULL) {
        ptr->next = list1;
        ptr = list1;
        list1 = list1->next;
    }

    // If any nodes remain in list2, append them to the merged list.
    while(list2 != NULL) {
        ptr->next = list2;
        ptr = list2;
        list2 = list2->next;
    }

    // The merged list starts from ans->next (skip the dummy node).
    return ans->next;
}
