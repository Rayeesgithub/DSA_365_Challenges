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


    
// -------------------------------------------
// Function to merge two sorted bottom lists
// -------------------------------------------
Node* mergeList(Node* a, Node* b) {
    
    // Base cases
    if(a == NULL) return b;
    if(b == NULL) return a;

    // Result node pointer
    Node* result;

    // Choose smaller value node and merge recursively
    if(a->data < b->data) {
        result = a;
        result->bottom = mergeList(a->bottom, b);
    }
    else {
        result = b;
        result->bottom = mergeList(a, b->bottom);
    }

    result->next = NULL; // Important
    return result;
}


// -------------------------------------------
// Function to flatten the linked list
// -------------------------------------------
Node* flatten(Node* root) {

    // Base case: empty list or only one linked list
    if(root == NULL || root->next == NULL)
        return root;

    // 1. Recursively flatten the next list
    root->next = flatten(root->next);

    // 2. Merge current list with the already flattened list
    root = mergeList(root, root->next);

    return root; 
}
