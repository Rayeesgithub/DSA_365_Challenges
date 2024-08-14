https://leetcode.com/problems/add-two-numbers/
//striver..

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Create a dummy node to act as
    ListNode* dummy = new ListNode();
  ListNode* temp = dummy; // A pointer to traverse and build the new linked list.
    
    // Initialize the carry to 0. This will be used to handle sums greater than 9.
    int carry = 0;

    // Continue looping until both l1 and l2 are fully traversed and no carry remains.
    while(l1 != NULL || l2 != NULL || carry) {
        int sum = 0; // Initialize the sum for the current digit.

        // If l1 is not null, add its value to the sum and move to the next node in l1.
        if(l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        // If l2 is not null, add its value to the sum and move to the next node in l2.
        if(l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        // Add any carry from the previous iteration to the sum.
        sum += carry;

        // Calculate the new carry by dividing the sum by 10.
        // If the sum is 10 or more, carry will be 1 (for the next digit), otherwise 0.
        carry = sum / 10;

        // Create a new node for the digit at the current position (sum % 10).
        ListNode *digit = new ListNode(sum % 10);

        // Link the newly created node to the result linked list.
        temp->next = digit;

        // Move the temp pointer to the next position in the list.
        temp = temp->next;
    }

    // Return the head of the result linked list, which starts at dummy->next.
    return dummy->next;
}
