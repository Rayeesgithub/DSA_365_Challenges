//striver sheet

//https://leetcode.com/problems/sort-list/description/

Input: head = [4,2,1,3]
Output: [1,2,3,4]


  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node to build the merged sorted list
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // Merge both lists until one becomes NULL
        while (list1 != NULL && list2 != NULL) {

            // Pick the smaller value and attach it to result
            if (list1->val < list2->val) {
                temp->next = list1;     // attach list1 node
                list1 = list1->next;    // move list1 forward
            }
            else {
                temp->next = list2;     // attach list2 node
                list2 = list2->next;    // move list2 forward
            }

            temp = temp->next;         // move result pointer forward
        }

        // Attach remaining nodes of whichever list is not empty
        if (list1 != NULL) {
            temp->next = list1;
        }
        else {
            temp->next = list2;
        }

        // The merged sorted list starts from dummy->next
        return dummy->next;
    }




// ---------------------------------------------
// Find middle of linked list using slow-fast
// ---------------------------------------------
ListNode* findmid(ListNode* &head) {

        ListNode* slow = head;
        ListNode* fast = head->next;  
        // fast starts ahead to ensure mid moves correctly

        // fast moves 2 steps, slow moves 1 step
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow now points to mid node
        return slow;
    }




// ---------------------------------------------
// Main function: Sort list using Merge Sort
// ---------------------------------------------
ListNode* sortList(ListNode* head) {

        // Base condition: single node or empty list is already sorted
        if (head == NULL || head->next == NULL)
            return head;

        // 1) Find the mid of the linked list
        ListNode* mid = findmid(head);

        // 2) Split the list into two halves
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;     // break the list

        // 3) Recursively sort left and right halves
        left = sortList(left);
        right = sortList(right);

        // 4) Merge the two sorted halves
        return mergeTwoLists(left, right);
    }
