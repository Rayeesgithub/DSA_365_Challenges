https://leetcode.com/problems/palindrome-linked-list/description/
//striver]

  ListNode* getMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
        }
        return slow;
      }
      ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
      }

    bool isPalindrome(ListNode* head) {
         if(head->next == NULL){
        return true;
    }
        //step1
        ListNode* middle=getMiddle(head);
        // step2=
        ListNode* reverseHead=reverse(middle);
        // middle->next=reverseHead;
        //step3
       ListNode* temp1=head;
       ListNode* temp2=reverseHead;
       while(temp2!=NULL){
        if(temp1->val!=temp2->val){
       return false;
      }
      temp1=temp1->next;
      temp2=temp2->next;
       }
      
      return true;
    }
