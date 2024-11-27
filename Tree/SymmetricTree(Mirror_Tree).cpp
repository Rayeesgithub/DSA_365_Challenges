 bool isSame(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL){
            return true;
        }
        if(p!=NULL && q!=NULL && p->val==q->val){
            bool ans1=isSame(p->left,q->right);
            bool ans2=isSame(p->right,q->left);
            return ans1 && ans2;
        }
        return false;
     }
    bool isSymmetric(TreeNode* root) {
        bool ans=isSame(root->left,root->right);
        return ans;
    }
};
