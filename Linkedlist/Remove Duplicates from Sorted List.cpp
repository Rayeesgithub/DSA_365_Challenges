https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
// striver sheet

ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        while(curr!=NULL){
            if(curr->next!=NULL && curr->val==curr->next->val){
                curr->next=curr->next->next;
            }
            else{
                curr=curr->next;
            }
        }
        return head;
    }
};
