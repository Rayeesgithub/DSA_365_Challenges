//striver sheet

//https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

// Broute force
 ListNode* findMid(ListNode* &head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }
    return slow;
 }
    ListNode* deleteMiddle(ListNode* head) {
          if (head == NULL) return NULL;  // Handle the case of an empty list
         if (head->next == NULL) {       // Handle the case of a single node
           return NULL;
    }
        ListNode* mid=findMid(head);
        ListNode* temp=head;
       ListNode* prev=NULL;
       while(temp!=NULL && temp!=mid){
        prev=temp;
        temp=temp->next;
       }
       if(prev!=NULL && temp!=NULL){
        prev->next=temp->next;
        delete temp;
       }
        

        return head;
    }
};
