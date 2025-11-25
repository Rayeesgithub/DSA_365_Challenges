head=1 2 3 4 5  ,  key=3  return true
head=1 2 3 4 5 ,  key=8   return false


bool searchKey(Node* head, int key) {

    // Start traversing the list from the head
    Node* temp = head;

    // Loop until we reach the end of the linked list
    while(temp != NULL) {

        // Check if current node's data matches the key
        if(temp->data == key) {
            return true;  // Key found ✔
        }

        // Move to the next node
        temp = temp->next;
    }

    // If loop ends and key not found, return false
    return false;
}
