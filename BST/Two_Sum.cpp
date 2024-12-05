void inorder(TreeNode* root, vector<int>&ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
   bool TwoSum(TreeNode* root,int k,vector<int>&ans){
    if(root==NULL){
        return false;
    }
    int s=0; int e=ans.size()-1;
    while(s<e){
        if(ans[s]+ans[e]==k){
            return true;
        }
        else if(ans[s]+ans[e]>k){
         e--;
        }
        else{
            s++;
        }
    }
    return false;
   }
    bool findTarget(TreeNode* root, int k) {
      vector<int>ans;
      inorder(root,ans); 
      bool result=TwoSum(root,k,ans); 
      return result;
    }
};
