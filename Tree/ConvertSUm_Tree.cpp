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
    if(data==-1){
        return NULL;
    } 

    Node* root=new Node(data);
    int leftData;
    cout<<"enter the left data:";
    cin>>leftData;
     cout<<endl;
    root->left=buildTree(leftData);
  
 
  int rightData;
  cout<<"enter the right data:";
  cin>>rightData;
  root->right=buildTree(rightData);

  return root;
}
int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int leftHeight=height(root->left);
    int rightHeight=height(root->right);

    int ans=max(leftHeight,rightHeight)+1;
    return ans;
}
int convertSumTree(Node* root){
    if(root==NULL){
        return 0;
    }
  int leftsum=convertSumTree(root->left);
  int rightsum=convertSumTree(root->right);

  root->data=root->data+leftsum+rightsum;

  return root->data;
}
int main(){
   Node* root;
    int data;
    cout<<"enter the date for Root Node:";
    cin>>data;
    root=buildTree(data);
   int ans=height(root);
   
   int ans1=convertSumTree(root);
   cout<<"root sum is:"<<ans1;
}
