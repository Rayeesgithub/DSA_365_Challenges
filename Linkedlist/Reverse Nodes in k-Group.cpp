https://leetcode.com/problems/reverse-nodes-in-k-group/description/

//striver sheet

// leetcode
int getLength(ListNode* head){
    int len=0;
    ListNode* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
ListNode*  reverse(ListNode* head,int k){
  if(head == NULL){
        return head;
    }
    // Invalid case
    int len = getLength(head);
    if(k > len){
        return head;
    }
    // Step - 1 => Reverse first k nodes
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* forward = curr->next;
    int count = 0;
    while(count < k  && curr != nullptr){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    // Step - 2 => Recursion 
    if(forward != NULL){ // We still have nodes left to reverse
        head->next = reverse(forward,k); // Connection step
    }
    // Return head 
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
      
        return reverse(head,k);
    }
};




// gfg

