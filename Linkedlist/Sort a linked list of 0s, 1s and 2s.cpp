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


// 2nd approach
  Node* segregate(Node *head) {
        
        // Add code here
        Node* zerohead=new Node(-1);
        Node* zerotail=zerohead;
        
        Node* onehead=new Node(-1);
        Node* onetail=onehead;
        
        Node* twohead=new Node(-1);
        Node* twotail=twohead;
        
        Node* curr=head;
        while(curr!=NULL){
            if(curr->data==0){
                Node* temp=curr;
                curr=curr->next;
                temp->next=NULL;
                  // Append the zero node
                  zerotail->next=temp;
                  zerotail=temp;
            }
            else  if(curr->data==1){
                Node* temp=curr;
                curr=curr->next;
                temp->next=NULL;
                  // Append the zero node
                  onetail->next=temp;
                  onetail=temp;
            }
            else  if(curr->data==2){
                Node* temp=curr;
                curr=curr->next;
                temp->next=NULL;
                  // Append the zero node
                  twotail->next=temp;
                  twotail=temp;
            }
        }
        
         Node* temp = onehead;
    onehead = onehead -> next;
    temp->next = NULL;
    delete temp;
    // Modify twoHead Linked List
    temp = twohead;
    twohead = twohead->next;
    temp->next = NULL;
    delete temp;
    // Join List
    if(onehead!=NULL){
        // oneHead Linked List is non-empty
        zerotail->next = onehead;
        if(twohead != NULL){
            onetail->next = twohead;
        }
    }
    else{
        // oneHead Linked List is empty this means

        if(twohead != NULL){
            zerotail->next = twohead;
        }
    }
    // Remove zeroHead dummy node
    temp = zerohead;
    zerohead = zerohead->next;
    temp->next = NULL;
    delete temp;
    // return head
    return zerohead;
        
    }
