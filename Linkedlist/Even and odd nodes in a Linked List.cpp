Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]


ListNode* oddEvenList(ListNode* head) {

    // If list has 0 or 1 nodes → return as it is
    if (!head || !head->next) return head;

    // odd pointer starts at first node
    ListNode* odd = head;

    // even pointer starts at second node
    ListNode* even = head->next;

    // Save start of even list to connect later
    ListNode* evenHead = even;

    // We separate odd and even nodes
    while (even != NULL && even->next != NULL) {

        // Connect odd nodes
        odd->next = even->next;
        odd = odd->next;  // move odd pointer

        // Connect even nodes
        even->next = odd->next;
        even = even->next;  // move even pointer
    }

    // Finally attach even list after odd list
    odd->next = evenHead;

    return head;
}





// another approach

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
