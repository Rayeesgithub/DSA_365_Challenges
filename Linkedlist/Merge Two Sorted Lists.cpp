//LOVE BABBAR SHEET
https://leetcode.com/problems/merge-two-sorted-lists/description/

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    // Dummy node: helps in building the merged list easily
    ListNode* dummy = new ListNode(-1);

    // 'temp' will move forward and build the new list
    ListNode* temp = dummy;

    // Traverse both lists until one becomes NULL
    while (list1 != NULL && list2 != NULL) {

        // Pick the smaller value and attach it to temp->next
        if (list1->val < list2->val) {

            temp->next = list1;   // connect list1 node
            list1 = list1->next;  // move list1 pointer

        } else {

            temp->next = list2;   // connect list2 node
            list2 = list2->next;  // move list2 pointer
        }

        temp = temp->next;  // move temp forward
    }

    // Attach remaining elements of whichever list is not empty
    if (list1 != NULL)
        temp->next = list1;
    else
        temp->next = list2;

    // Return the merged list (dummy->next is the real head)
    return dummy->next;
}
