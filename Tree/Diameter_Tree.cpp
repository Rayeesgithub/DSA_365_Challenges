// Broute force-> Time-Com=0(N^2)
int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int leftHeight=height(root->left);

    int rightHeight=height(root->right);

    int ans=max(leftHeight,rightHeight)+1;

    return ans;
 }
 int Diameter(Node * root){
    if(root==NULL){
        return 0;
    }

    int leftDia=Diameter(root->left);
    int rightrDia=Diameter(root->right);

    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    int ans=leftHeight+rightHeight;

    int res=max(ans,max(leftDia,rightrDia));

    return res;
 }






// optimal Approach Time-Com=0(N)
int Dia=0;
int height(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    int currD=lh+rh;
    Dia=max(Dia,currD);
    return max(lh,rh)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
       int ans= height(root);
       return Dia;
    }
};
