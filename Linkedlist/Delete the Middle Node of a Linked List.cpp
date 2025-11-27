//striver sheet

//https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

// Broute force
ListNode* findmid(ListNode* &head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;       // middle node
}

ListNode* deleteMiddle(ListNode* head) {

    // ⭐ Case 1: Only 1 node
    if(head == NULL || head->next == NULL)
        return NULL;

    ListNode* mid = findmid(head);
    ListNode* temp = head;
    ListNode* prev = NULL;

    // ⭐ Find the node just one before mid
    while(temp != mid){
        prev = temp;
        temp = temp->next;
    }

    // ⭐ Delete middle
    prev->next = temp->next;
    delete temp;

    return head;
}
