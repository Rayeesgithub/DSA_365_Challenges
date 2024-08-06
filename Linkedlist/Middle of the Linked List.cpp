https://leetcode.com/problems/middle-of-the-linked-list/description/
// striver sheet


 int getMiddle(Node* head) {
          Node* slow=head;
         Node* fast=head;
        if(head==NULL || head->next==NULL){
            return head->data;
        }
        while(slow!=NULL && fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }

        }
        return slow->data;
    }
