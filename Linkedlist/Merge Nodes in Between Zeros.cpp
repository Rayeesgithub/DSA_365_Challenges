Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.


  ListNode* mergeNodes(ListNode* head) {
    ListNode* temp = head->next;   // Skip the first 0
    ListNode* ansHead = new ListNode(0);
    ListNode* ans = ansHead;

    int sum = 0;

    while (temp != nullptr) {

        if (temp->val != 0) {
            sum += temp->val;   // Add values until we find 0
        } 
        else {
            // We reached a zero → create node with sum
            ans->next = new ListNode(sum);
            ans = ans->next;
            sum = 0;            // Reset for next segment
        }

        temp = temp->next;
    }

    return ansHead->next;  
}
