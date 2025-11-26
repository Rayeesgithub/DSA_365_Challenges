https://leetcode.com/problems/add-two-numbers/
///striver sheet

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    // Dummy node to build the resulting linked list.
    ListNode* dummy = new ListNode();

    // Pointer to move and attach new nodes
    ListNode* temp = dummy;

    // Carry for addition (ex: 9 + 9 = 18 → carry = 1)
    int carry = 0;

    // Traverse both lists until both end AND carry becomes 0
    while ((l1 != NULL || l2 != NULL) || carry) {

        int sum = 0;  // store digit-by-digit sum

        // If l1 has a node, add its value
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;  // move forward in l1
        }

        // If l2 has a node, add its value
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;  // move forward in l2
        }

        // Add previous carry
        sum += carry;

        // New carry for next digit
        carry = sum / 10;

        // Final digit to store (ones place only)
        int digit = sum % 10;

        // Create a new node with this digit
        ListNode* node = new ListNode(digit);

        // Attach to result list
        temp->next = node;

        // Move temp forward
        temp = temp->next;
    }

    // The real result starts after dummy node
    return dummy->next;
}
