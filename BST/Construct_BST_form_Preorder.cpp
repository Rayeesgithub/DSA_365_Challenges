// Broute force
int findpos(vector<int>&Inorder,int n, int element){
    for(int i=0; i<n; i++){
        if(Inorder[i]==element){
            return i;
        }
    }
    return -1;
}
 TreeNode* solve(vector<int>& preorder,vector<int>&Inorder,int &preIndex, int     size,int inorderStart,int inorderEnd){
        if(inorderStart>inorderEnd || preIndex>size){
            return NULL;
        }
        int element=preorder[preIndex++];
        TreeNode* root=new TreeNode(element);
        int pos=findpos(Inorder,size,element);
        root->left=solve(preorder,Inorder,preIndex,size,inorderStart,pos-1);
        root->right=solve(preorder,Inorder,preIndex,size,pos+1,inorderEnd);
        return root;
      }
    TreeNode* bstFromPreorder(vector<int>& preorder) { 

       vector<int>Inorder=preorder;
       sort(Inorder.begin(),Inorder.end());
       int preIndex=0; int size=Inorder.size();
       int InorderStart=0; int InorderEnd=Inorder.size()-1;
       return solve(preorder,Inorder,preIndex,size,InorderStart,InorderEnd);


   
      
      // optimal approach
       TreeNode* BuiltBST(vector<int>&preorder,int min,int max,int &index){
         if (index >= preorder.size()) {
            return NULL; // If we've processed all elements in the preorder sequence, return NULL.
        }
        TreeNode* root = NULL;

        // Check if the current value is within the acceptable range (min < value < max).
        if (preorder[index] > min && preorder[index] < max) {
            // Create a new TreeNode with the current value and increment the index.
            root = new TreeNode(preorder[index++]);

            // Recursively build the left and right subtrees with updated min and max values.
            root->left = BuiltBST(preorder, min, root->val, index);
            root->right = BuiltBST(preorder, root->val, max, index);
        }
        return root; // Return the constructed subtree rooted at "root".
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min=INT_MIN; int max=INT_MAX;
        int i=0;
       return  BuiltBST(preorder,min,max,i);
    }
};
      
    
    }
