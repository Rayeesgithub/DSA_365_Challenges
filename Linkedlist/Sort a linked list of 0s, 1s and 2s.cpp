//striver sheet
https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

//approach1

  Node* segregate(Node *head) {
        
        // Add code here
           // Add code here
        int zerocount=0;
        int onecount=0; 
        int twocount=0;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==0) {
                zerocount++;
            }
           else if(temp->data==1){
                onecount++;
            }
         else{
                twocount++;
        }
        temp=temp->next;
        }
        temp=head;
        while(zerocount--){
            temp->data=0;
            temp=temp->next;
        }
        while(onecount--){
            temp->data=1;
            temp=temp->next;
        }
        while(twocount--){
            temp->data=2;
            temp=temp->next;
        }
        return head;
    }
};
