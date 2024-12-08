//love sheet

class Solution {
public:
void Inorder(TreeNode* root,vector<int>&ans){
   if(root==NULL) return;
   Inorder(root->left,ans);
   ans.push_back(root->val);
   Inorder(root->right,ans);
}
  TreeNode* buildBalence(vector<int>&ans,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    TreeNode* root=new TreeNode(ans[mid]);
    root->left=buildBalence(ans,s,mid-1);
    root->right=buildBalence(ans,mid+1,e);
    return root; 
  }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        Inorder(root,ans); 
        int s=0; int e=ans.size()-1; 
       
        return buildBalence(ans,s,e);
    }
};
