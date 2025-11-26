https://leetcode.com/problems/reverse-nodes-in-k-group/description/

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]


    Steps which we followed
(1) Reverse first k nodes.
(2) Find answer of recursion
 (3) Connection step head +next = ans of recusion
(4) Return new head lie. prev.

    
    



    
    // leetcode
// Function to calculate the total length of the linked list
int getLength(ListNode* &head){
    int len = 0;                 // length counter
    ListNode* temp = head;       // temporary pointer to traverse

    // traverse until the end of the list
    while(temp != NULL){
        temp = temp->next;       // move to next node
        len++;                   // increase length count
    }
    return len;                  // return total length
}



// Function to reverse nodes in groups of size k
ListNode* reverseGroup(ListNode* &head, int k){

    // if list is empty, no reversal is needed
    if(head == NULL) 
        return head;

    // find total length
    int len = getLength(head);

    // if k is greater than total nodes, cannot reverse → return original list
    if(k > len){
        return head;
    }

    int count = 0;               // count nodes reversed in current group
    ListNode* prev = NULL;       // previous pointer for reversing
    ListNode* curr = head;       // current pointer
    ListNode* forward = curr->next; // forward pointer to store next node

    // reverse first k nodes
    while(count < k && curr != NULL){
        forward = curr->next;    // store next node
        curr->next = prev;       // reverse the link
        prev = curr;             // move prev one step forward
        curr = forward;          // move curr one step forward

        count++;                 // increase reversed count
    }

    // After reversing k nodes:
    // 'head' becomes the last node of this reversed group
    // connect it with the next reversed groups recursively
    if(forward != NULL){
        head->next = reverseKGroup(forward, k);
    }

    // 'prev' is now the new head of this reversed block
    return prev;
}



// Main function that calls reverseGroup
ListNode* reverseKGroup(ListNode* head, int k) {
    return reverseGroup(head, k);
}
