Linked List:  1 → 2 → 3 → 4 → 5
                      ↑       ↓
                      └───────┘
Cycle: Node 5 → next = Node 3

  Dry run->
  | Step      | slow         | fast         | Remark                           |
| --------- | ------------ | ------------ | -------------------------------- |
| Start     | 1            | 1            | Both at head                     |
| 1         | 2            | 3            | fast jumps 1→3                   |
| 2         | 3            | 5            | fast jumps 3→5                   |
| 3         | 4            | 4            | fast jumps 5→4 (cycle)           |
| **Meet?** | **slow = 4** | **fast = 4** | **Cycle detected → return true** |




bool hasCycle(ListNode *head) {
        
        // If list is empty → no cycle possible
        if(head == NULL){
            return false;
        }

        // Initialize two pointers
        ListNode* slow = head;    // moves 1 step
        ListNode* fast = head;    // moves 2 steps

        // Loop until fast reaches end (NULL → no cycle)
        while(fast != NULL && fast->next != NULL){

            fast = fast->next->next;  // fast moves 2 steps
            slow = slow->next;        // slow moves 1 step

            // If slow and fast meet at same node → cycle exists
            if(fast == slow){
                return true;
            }
        }

        // If loop breaks without meeting → no cycle
        return false;
    }




// 2nd approach->
bool detectLoop(Node* head) {
        // Initialize a pointer at head
        Node* temp = head;

        // Create a map to keep track of visited nodes
        unordered_map<Node*, int> nodeMap;

        // Traverse the linked list
        while (temp != nullptr) {
            // If node already exists in map, loop detected
            if (nodeMap.find(temp) != nodeMap.end()) {
                return true;
            }
            // Store the current node in the map
            nodeMap[temp] = 1;

            // Move to the next node
            temp = temp->next;
        }

        // If traversal completes, no loop detected
        return false;
    }
