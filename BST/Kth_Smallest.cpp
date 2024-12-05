

// Broute force-> APPROACH1
#include<bits/stdc++.h>
using namespace std;
 
 class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
 };
 Node* insertBST(Node* root, int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(root->data > data){
        root->left=insertBST(root->left,data);
    }
    else{
        root->right=insertBST(root->right,data);
    }
    return root;
 }
   void TakeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertBST(root,data);
        cin>>data;
    }
   }
void inorder(Node* root, vector<int>&ans){
    if(root==NULL) return;
   inorder(root->left,ans);
   ans.push_back(root->data);
   inorder(root->right,ans);
}
    int kthSmallest(Node* root, int k) {
        vector<int>ans;
        inorder(root,ans);
        int res=0;
        for(int i=0; i<ans.size(); i++){
          res=ans[k-1];
        }
        return res;
    }

 int main(){
    Node* root=NULL;
    cout<<"enter the elemnt is:";
    TakeInput(root);
    // LevelOrderTraversal(root);
    int k=2;
    int ans=kthSmallest(root,k);
    cout<<"kth Minimum Elemnt is:"<<ans;
 }







// OPTIMAL-> approach
void  findKthSmall(TreeNode* root,int k,int &count,int &ans){
    if(root==NULL)return;
    findKthSmall(root->left,k,count,ans);
    count++;
    if(count==k){
        ans=root->val;
        return;
    }
    findKthSmall(root->right,k,count,ans);
}
    int kthSmallest(TreeNode* root, int k) {
       int count=0;
       int ans=0;
       findKthSmall(root,k,count,ans);  
       return ans;
    }
};

