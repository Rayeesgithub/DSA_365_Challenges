  void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        while (root) {
            if (root->left) { // If the current node has a left subtree.
                TreeNode* pred = root->left; // Initialize 'pred' as the left child.
                while (pred->right) {
                    pred = pred->right; // Find the rightmost node in the left subtree.
                }
                pred->right = root->right; // Point the right of the rightmost node to the right subtree.
                root->right = root->left; // Point the right of the current node to the left subtree.
                root->left = NULL; // Set the left of the current node to NULL to break the connection with the left subtree.
            }
            root = root->right; // Move to the next node in the tree.
        }
    }
