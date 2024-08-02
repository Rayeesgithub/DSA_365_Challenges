// striver sheet

  Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* newNode=new Node(x);
        
             // If the list is empty, return the new node as the new head
    if (head == nullptr) {
        return newNode;
    }

    // Traverse to the end of the list
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Append the new node at the end
    temp->next = newNode;
    
    // Return the head of the list
    return head;
    }
