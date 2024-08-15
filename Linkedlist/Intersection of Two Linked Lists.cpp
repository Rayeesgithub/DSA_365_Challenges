https://leetcode.com/problems/intersection-of-two-linked-lists/description/
//striver sheet

//approach-1
Brute Force Solution
Time Complexity : O(m * n)
Space Complexity : O(1)

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *temp;
		while(headA != NULL){
			temp = headB;
			while(temp != NULL){
				if(headA == temp){
					return headA;
				}
				temp = temp -> next;
			}
			headA = headA -> next;
		}
		return NULL;
	}
};


//optimal Approach
Time Complexity : O(m + n)
Space Complexity : O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Initialize pointers to the heads of the linked lists
        ListNode *a = headA;
        ListNode *b = headB;

        // Traverse the lists until one of them reaches the end
        while (a->next && b->next) {
            // Check if the current nodes are the same (intersection found)
            if (a == b) {
                return a;  // Return the intersection node
            }
            // Move to the next nodes in both lists
            a = a->next;
            b = b->next;
        }

        // If the above loop finishes, it means one of the lists has reached its end
        // Check if both lists have reached the same end
        while (a->next && b->next && a != b) {
            return 0;  // Return 0 (nullptr) indicating no intersection
        }

        // Determine which list has a larger length
        int blen = 0;
        if (a->next == NULL) {
            // Calculate the length of list B
            while (b->next) {
                b = b->next;
                blen++;
            }
            // Adjust the starting position of list B to match the shorter list
            while (blen--) {
                headB = headB->next;
            }
        } else {
            // Calculate the length of list A
            int alen = 0;
            while (a->next) {
                a = a->next;
                alen++;
            }
            // Adjust the starting position of list A to match the shorter list
            while (alen--) {
                headA = headA->next;
            }
        }

        // Traverse both lists until they meet at the intersection point
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        // Return the intersection node or nullptr if no intersection
        return headA;
    }

