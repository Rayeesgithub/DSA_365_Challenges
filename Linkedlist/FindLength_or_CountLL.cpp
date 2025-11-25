//striver sheet
https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-nodes-of-linked-list


int getCount(Node* head) {
    int len = 0;        // Initialize a counter to count number of nodes
    
    Node* temp = head;  // Create a pointer to traverse the linked list
    
    // Loop until we reach the end of the list
    while (temp != NULL) {
        temp = temp->next; // Move to next node
        len++;             // Increase count for each node visited
    }
    
    return len;  // Return the total number of nodes counted
}
