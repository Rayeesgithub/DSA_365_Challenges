//striver sheet

//https://leetcode.com/problems/sort-list/description/

ListNode* findmid(ListNode* &head){
  ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
}
ListNode* mergeList(ListNode* list1, ListNode* list2) {
        ListNode* ans=new ListNode(-1);
        ListNode* ptr=ans;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                ptr->next=list1;
                ptr=list1;
                list1=list1->next;
            }
            else {
                ptr->next=list2;
                ptr=list2;
                list2=list2->next;
            }
        }
        while(list1!=NULL){
            ptr->next=list1;
                ptr=list1;
                list1=list1->next;
        }
        while(list2!=NULL){
             ptr->next=list2;
                ptr=list2;
                list2=list2->next;
        }
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid=findmid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        left=sortList(left);
        right=sortList(right);
        return mergeList(left,right);
    }
};
