  bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        if(p!=NULL && q!=NULL && p->val==q->val){
            bool leftAns=isSameTree(p->left,q->left);
            bool rightAns=isSameTree(p->right,q->right);

            return leftAns && rightAns;
        }

        return false;
    }
