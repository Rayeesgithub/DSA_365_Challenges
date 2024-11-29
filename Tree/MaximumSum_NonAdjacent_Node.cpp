
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
 Node* buildTree(int data){
    // base case
    if(data==-1){
        return NULL;
    }

    // create a newNodee
      Node *root = new Node(data);
      int leftData;
      cout<<"enter the left Data:";
      cin>>leftData;
       cout<<endl;
      root->left=buildTree(leftData);
      
      int rightData;
      cout<<"enter the rightdata:";
      cin>>rightData;

      root->right=buildTree(rightData);

      return root;
 }
  pair<int,int>getMaxSum(Node* root){
    if(root==NULL){
        return {0,0};
    }

 auto leftSum=getMaxSum(root->left);
 auto rightSum=getMaxSum(root->right);

 int include=root->data+leftSum.second+rightSum.second;
 int exclude=max(leftSum.first,leftSum.second) + max(rightSum.first,rightSum.second);
   return {include,exclude};
  }
int main(){
    Node* root;
    int data;
    cout<<"enter the date for Root Node:";
    cin>>data;
    root=buildTree(data);
 auto ans=getMaxSum(root);

  auto res=max(ans.first,ans.second);
    
   cout<<"Maximum sum of Tree is:"<<res; 
}
