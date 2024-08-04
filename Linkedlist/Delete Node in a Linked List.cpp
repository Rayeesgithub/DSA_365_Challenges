//striver
https://leetcode.com/problems/delete-node-in-a-linked-list/description/

void deleteNode(ListNode* node) {
    // Step 1: Store the pointer to the next node
    ListNode* temp = node->next;

    // Step 2: Copy the value of the next node to the current node
    node->val = temp->val;

    // Step 3: Update the current node's next pointer to skip the next node
    node->next = temp->next;

    // Step 4: Delete the next node (which has been effectively removed from the list)
    delete temp;
}
