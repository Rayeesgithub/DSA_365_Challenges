https://leetcode.com/problems/linked-list-cycle-ii/description/
// striver sheet

 ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
         fast=fast->next;
         if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
         }    
         if(slow==fast){
            slow=head;
            break;
         }
      
        }
        while(slow!=fast && fast!=NULL){
               slow=slow->next;
             fast=fast->next;
        }
        if(fast==NULL){
            return NULL;
        }
        return slow;
    }
};
