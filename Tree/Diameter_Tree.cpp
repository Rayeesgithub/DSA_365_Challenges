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
