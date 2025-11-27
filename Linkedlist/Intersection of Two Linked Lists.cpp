https://leetcode.com/problems/intersection-of-two-linked-lists/description/
//striver sheet

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5],
	// here 1 refr diffrent memory location where as 8 refer same memorry location

	// apprach1
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // Create a hash set to store addresses of nodes from List A
        unordered_set<ListNode*> st;

        // Step 1: Insert every node of List A into the set
        while(headA != NULL){
            st.insert(headA);        // store the address (node pointer)
            headA = headA->next;     // move to next node
        }

        // Step 2: Now traverse List B and check if any node exists in the set
        while(headB != NULL){
            if(st.find(headB) != st.end()){
                // If found → this is the intersection node
                return headB;
            }
            headB = headB->next;     // move forward
        }

        // No intersection
        return NULL;
}


//2nd approach
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    // Create two pointers:
    // d1 starts on List A, d2 starts on List B
    ListNode* d1 = headA;
    ListNode* d2 = headB;

    // Loop continues until both pointers meet
    // They will meet either at:
    // 1) Intersection node, OR
    // 2) Both become NULL (no intersection)
    while (d1 != d2) {
        
        // If d1 reaches end of List A,
        // move it to start of List B
        // Otherwise move to next node
        d1 = (d1 == NULL) ? headB : d1->next;

        // If d2 reaches end of List B,
        // move it to start of List A
        // Otherwise move to next node
        d2 = (d2 == NULL) ? headA : d2->next;
    }

    // Either intersection node OR NULL
    return d2;
}






//optimal Approach
Time Complexity : O(m + n)
Space Complexity : O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Initialize pointers to the heads of the linked lists
        ListNode *a = headA;
        ListNode *b = headB;

        // Traverse the lists until one of them reaches the end
        while (a->next && b->next) {
            // Check if the current nodes are the same (intersection found)
            if (a == b) {
                return a;  // Return the intersection node
            }
            // Move to the next nodes in both lists
            a = a->next;
            b = b->next;
        }

       

        // Determine which list has a larger length
        int blen = 0;
        if (a->next == NULL) {
            // Calculate the length of list B
            while (b->next) {
                b = b->next;
                blen++;
            }
            // Adjust the starting position of list B to match the shorter list
            while (blen--) {
                headB = headB->next;
            }
        } else {
            // Calculate the length of list A
            int alen = 0;
            while (a->next) {
                a = a->next;
                alen++;
            }
            // Adjust the starting position of list A to match the shorter list
            while (alen--) {
                headA = headA->next;
            }
        }

        // Traverse both lists until they meet at the intersection point
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        // Return the intersection node or nullptr if no intersection
        return headA;
    }

