https://leetcode.com/problems/reverse-linked-list/description/
striver sheet


// by loop apprach
ListNode* reverseList(ListNode* head) {
    // Initialize three pointers: prev (to NULL), curr (to head), and forward (initially not used)
    ListNode* prev = NULL;   
    ListNode* curr = head;    // This pointer is used to traverse the list

    while (curr != NULL) {
        // Step 1: Store the next node (forward) to keep track of the remaining list
        ListNode* forward = curr->next; // forward is used to temporarily hold the next node

        // Step 2: Reverse the current node's pointer to point to the previous node
        curr->next = prev; 

        // Step 3: Move the prev pointer to the current node (advance prev one step)
        prev = curr; 

        // Step 4: Move the curr pointer to the next node (advance curr one step)
        curr = forward; 
    }
    
    // At the end of the loop, prev will be pointing to the new head of the reversed list
    return prev;



// Recursive Approach
 ListNode* reverseFxn(ListNode* prev, ListNode* curr){
           if(curr==NULL){
            return prev;
        }
        ListNode* forward=curr->next;
        curr->next=prev;
       return reverseFxn(curr,forward);
    }
    ListNode* reverseList(ListNode* head) {
         ListNode* prev=NULL;
         ListNode* curr=head;
     
       
        return  reverseFxn(prev,curr);
       
    }
};
