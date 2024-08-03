// Love Babbar 
https://www.geeksforgeeks.org/problems/node-at-a-given-index-in-linked-list/1

 int GetNth(Node *head, int index) {
        // Code Here
        int position=1;
        Node* Current=head;
        while(Current!=NULL && position<index){
            Current=Current->next;
            position++;
        }
        
        if(Current==NULL){
            return -1;
        }
        
        return Current->data;
    }
