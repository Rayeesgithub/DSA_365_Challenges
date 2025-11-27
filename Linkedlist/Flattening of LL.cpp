GFG
striver sheet
input-> 
5 -> 10 -> 19 -> 28
|     |      |     |
7     20     22    35
|            |     |
8            50    40
|                  |
30                 45

Output: 5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.


    
Node* merge(Node* a, Node* b) {
    // If the first list (a) is empty, return the second list (b)
    if(!a) return b;
    
    // If the second list (b) is empty, return the first list (a)
    if(!b) return a;

    // Pointer to store the result of the merge
    Node* ans = 0;

    // Compare the data of the nodes pointed to by a and b
    if(a->data < b->data) {
        ans = a; // If a's data is smaller, a becomes the head of the merged list
        a->bottom = merge(a->bottom, b); // Recursively merge the rest of a and b
    } else {
        ans = b; // If b's data is smaller, b becomes the head of the merged list
        b->bottom = merge(a, b->bottom); // Recursively merge a and the rest of b
    }

    return ans; // Return the merged linked list
}

Node *flatten(Node *root) {
    // Base case: If the root is NULL, return NULL (i.e., the flattened list is empty)
    if(root == NULL) return 0;

    // Recursively flatten the list connected by `next` pointers and merge it with the current list
    Node* mergeLL = merge(root, flatten(root->next));

    return mergeLL; // Return the head of the flattened list
}
