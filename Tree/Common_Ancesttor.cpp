 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return 0;

        if(root->val==p->val){
            return p;
        }
        if(root->val==q->val){
            return q;
        }
        TreeNode* leftans=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans=lowestCommonAncestor(root->right,p,q);

        if(leftans==NULL && rightans==NULL){
            return NULL;
        }
        else if(leftans==NULL && rightans!=NULL){
            return rightans;
        }
         else if(leftans!=NULL && rightans==NULL){
            return leftans;
        }
        else{
            return root;
        }
    }
