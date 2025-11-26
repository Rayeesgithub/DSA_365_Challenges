https://leetcode.com/problems/palindrome-linked-list/description/

Input->
1 → 2 → 3 → 2 → 1
Output-> true

// Broute force 1
bool isPalindrome(ListNode* head) {
    vector<int> ans;
    ListNode* temp = head;

    // Step 1: store all node values into array(linklist  copy into array)
    while(temp != NULL) {
        ans.push_back(temp->val);
        temp = temp->next;
    }

    int s = 0;
    int e = ans.size() - 1;

    // Step 2: compare from both ends
    while(s <= e) {
        if(ans[s] != ans[e]) {   // if any mismatch → not palindrome
            return false;
        }
        s++;
        e--;
    }
    return true;   // all pairs matched → palindrome
}


// Broute force2
bool isPalindrome(ListNode* head) {
         stack<int> st;

         // Step 1: Traverse the linked list and push all values into a stack
         // Stack will store values in reverse order (LIFO)
         ListNode *temp = head;
         while(temp != NULL){
            st.push(temp->val);   // push current node value
            temp = temp->next;    // move to next node
         }

         // Step 2: Traverse the list again and compare each value with stack top
         temp = head;
         while(temp != NULL){

            // If any value does NOT match the value popped from stack,
            // it means the list is NOT a palindrome
            if(temp->val != st.top()){
                return false;
            }

            st.pop();              // remove matched top element
            temp = temp->next;     // move forward in the list
         }

         // If all values matched, the list is a palindrome
         return true;
}



// optimal approach
 bool isPalindrome(ListNode* head) {
         if (head == NULL || head->next == NULL) {
        return true;  // It's a palindrome by definition
    }
      // STEP 1: Find middle using slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    // Now, slow is at the middle node

    // STEP 2: Reverse the second half of the list
    ListNode* prev = NULL;
    ListNode* curr = slow;
    ListNode* nextNode;

    while(curr != NULL){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // Now 'prev' is the head of reversed second half

    // STEP 3: Compare first half and reversed second half
    ListNode* first = head;
    ListNode* second = prev;

    while(second != NULL){
        if(first->val != second->val){
            return false;   // values do not match → not palindrome
        }
        first = first->next;
        second = second->next;
    }

    return true; // All values matched → palindrome
    }
