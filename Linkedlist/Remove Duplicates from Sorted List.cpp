https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
// striver sheet
Input:  head = [1, 1, 2, 3, 3]
Start at first 1
curr = 1, curr->next = 1
Values equal → delete next 1
New list:
1 → 2 → 3 → 3
curr = 2

curr->next = 3
Not equal → move curr
curr = 3, curr = first 3
curr->next = 3
Values equal → delete next 3

O/P-> 1 → 2 → 3


        
ListNode* deleteDuplicates(ListNode* head) {

    // If list is empty or has just one node → no duplicates possible
    if(head == NULL || head->next == NULL)
        return head;

    ListNode* curr = head;

    // Traverse the entire linked list
    while(curr != NULL) {

        // Check if next node exists AND both values are equal
        if(curr->next != NULL && curr->val == curr->next->val) {

            // Skip the duplicate node
            // curr->next is duplicate, so link to next->next
            curr->next = curr->next->next;
        }
        else {
            // Move forward only when no duplicate
            curr = curr->next;
        }
    }

    return head;  // Return the cleaned list
}





//2nd approach(Broute force)
ListNode* deleteDuplicates(ListNode* head) {

    if(head == NULL) return NULL;

    unordered_map<int, bool> mp; // stores values we have already seen

    ListNode* curr = head;
    ListNode* prev = NULL;

    while(curr != NULL) {

        // If value already exists in map → duplicate found
        if(mp[curr->val] == true) {

            // Remove the duplicate node
            prev->next = curr->next;
            curr = curr->next;
        }
        else {
            // Mark value as seen
            mp[curr->val] = true;

            // Move both pointers forward
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}
