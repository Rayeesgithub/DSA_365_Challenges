// love sheet

void Inorder(Node* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    Inorder(root->left,ans);
    ans.push_back(root->data);
    Inorder(root->right,ans);
    
}
float findMedian(struct Node *root)
{
     vector<int>ans;
     Inorder(root,ans);
    double result; int n=ans.size();
     if(n%2==0){
         float index1=n/2;
         float index2=(n/2+1);
         result=(ans[index1-1]+ans[index2-1])/2.0;
     }
     else{
         float i=(n+1)/2.0;
         result=ans[i-1];
     }
     return result;
}
