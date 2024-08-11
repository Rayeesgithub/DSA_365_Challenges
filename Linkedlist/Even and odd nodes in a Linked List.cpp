//striver
leetcode->
  ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenNode=even;
        while(even!=NULL && even->next!=NULL){
            //pahle odd then even connect
            odd->next=even->next;// move next odd node
            odd=odd->next; //
            //now head join
            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenNode;
        return head;
    }

//gfg
 Node *oddHead = new Node(-1), *oddTail = oddHead;
    Node *evenHead = new Node(-1), *evenTail = evenHead;
    Node *curr = head, *temp;
    while (curr)
    {
        // Breaking the Link of the curr Node.
        temp = curr;
        curr = curr->next;
        temp->next = nullptr;

        if (temp->data %2!= 0) // If odd Node,append to odd LinkedList
        {
            oddTail->next = temp;
            oddTail = temp;
        }
        else // If Even Node,append to even LinkedList
        {
            evenTail->next = temp;
            evenTail = temp;
        }
    }
    evenTail->next = oddHead->next; 
    // Appending Odd LinkedList at end of EvenLinkedList
    return evenHead->next;
    }
