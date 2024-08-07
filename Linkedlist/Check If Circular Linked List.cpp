// Love Babbar
      // Your code here
        if(head==NULL){
            return true;
        }
        Node*curr=head->next;
        while(curr!=head && curr!=NULL){
          curr=curr->next;
             
          
        }
        if(curr==head){
                return true;
           }   
        return false;
    }
