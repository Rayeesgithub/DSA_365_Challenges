void Inorder(Node* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    Inorder(root->left,ans);
    ans.push_back(root->data);
    Inorder(root->right,ans);
    
}
   Node* flat(vector<int>ans,int i){
       if(i>=ans.size())return NULL;
       
      Node* root1=new Node(ans[i]);
      root1->left=NULL;
      root1->right=flat(ans,i+1);
      return root1;
       
   }
    Node *flattenBST(Node *root)
    {
       vector<int>ans;
       Inorder(root,ans);
      return flat(ans,0); 
    }
