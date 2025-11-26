https://leetcode.com/problems/middle-of-the-linked-list/description/
// striver sheet

Input: head = [1,2,3,4,5]
Output: [3,4,5] or 3
Explanation: The middle node of the list is node 3.

// broute force

// Function to calculate the total length of the linked list
int getLength(ListNode* & head){
    ListNode* temp = head;   // Start from head
    int len = 0;             // Counter for nodes
    
    // Traverse until end
    while(temp != NULL){
        temp = temp->next;   // Move to next node
        len++;               // Increase the count
    }
    return len;              // Return total length
}

ListNode* middleNode(ListNode* head) {
    int len = getLength(head);  // Step 1: get total number of nodes
    
    int mid = (len / 2);        // Step 2: middle index (for even length, returns second middle)
    
    ListNode* temp = head;      // Start from head
    int currIndex = 0;          // Index counter
    
    // Step 3: Move temp pointer to the middle node
    while(currIndex < mid){
        temp = temp->next;      // Move forward
        currIndex++;            // Increment index
    }
    
    return temp;                // temp is now pointing to middle node
}





// Optimal Approach-> ✅ Middle of Linked List (Fast–Slow Pointer Method)
 ListNode* middleNode(ListNode* head) {

    // slow pointer moves 1 step at a time
    ListNode* slow = head;

    // fast pointer moves 2 steps at a time
    ListNode* fast = head;

    // Loop runs until fast reaches the end
    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;        // Move slow by 1 step
        fast = fast->next->next;  // Move fast by 2 steps
    }

    // When fast reaches NULL (end), slow will be at the middle
    return slow;
}
