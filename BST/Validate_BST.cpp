// Broute force
void Inorder(TreeNode* root, vector<int>&ans){
    if(root==NULL) return;

    Inorder(root->left,ans);
    ans.push_back(root->val);
    Inorder(root->right,ans);
  }
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        Inorder(root,ans);
        for(int i=0; i<ans.size()-1; i++){
            if(ans[i]>=ans[i+1]){
                return false;
            }
        }
       return true;
    }
};

// optimal approach
bool isBST(TreeNode* root, long lb, long up){
        if(root==NULL){
            return true;
        }
        if(root->val >lb && root->val < up){
            bool leftAns=isBST(root->left,lb,root->val);
            bool rightAns=isBST(root->right,root->val,up);
            return leftAns && rightAns;
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        long lb=LONG_MIN;
        long up=LONG_MAX;
        bool ans=isBST(root,lb,up);
        return ans;
    }
