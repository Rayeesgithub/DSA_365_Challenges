//https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
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
 pair<int,int>findHeight(Node* root){
         if(root==NULL){
             return {0,0};
         }
  auto lh=findHeight(root->left);
  auto rh=findHeight(root->right);
  int sum=root->data;
  if(lh.first==rh.first){
      sum+=lh.second>rh.second?lh.second:rh.second;
  }
  else if(lh.first>rh.first){
      sum+=lh.second;
  }
  else{
      sum+=rh.second;
      }
      
      return {max(lh.first,rh.first)+1,sum};
     }
int main(){
    Node* root;
    int data;
    cout<<"enter the date for Root Node:";
    cin>>data;
    root=buildTree(data);
    
    auto ans=findHeight(root);
    cout<<"Sum of Node of Longest Path is:"<<ans.second;
    
    

    
    
    
}
