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
Node *buildTree(int data)
{
    // -1 data indicates that we have the leaf node (Base Case)
    if (data == -1)
    {
        return NULL;
    }
    // Create the root node and hence solved 1 case
    Node *root =new Node(data);
    // Recursion will handle
    int leftData;
    cout << "Enter the data for left child of " << data << endl;
    cin >> leftData;
    root->left = buildTree(leftData);
    int rightData;
    cout << "Enter the data for right child of " << data << endl;
    cin >> rightData;
    root->right = buildTree(rightData);
    return root;
}
 void leftTravesal(Node* root){
    if(root==NULL){
        return;
    }
    //leafnode
    if(root->left==NULL && root->right==NULL){
        return;
    }
    cout<<root->data<<" ";
    if(root->left)
    leftTravesal(root->left);
    if(root->right)
    leftTravesal(root->right);
 }
 void leafNodeTraversal(Node* root){
    if(root==nullptr){
  return;
    }
    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
    }
    leafNodeTraversal(root->left);
    leafNodeTraversal(root->right);
 }
 void  rightTravesal(Node* root){
    if(root==NULL){
        return;
    }
  if(root->left==NULL && root->right==NULL){
    return;
  }
    if(root->right)
    rightTravesal(root->right);
    if(root->left){
        leftTravesal(root->left);
    }

    cout<<root->data<<" ";
 }
void BoundaryTraversal(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";

    // leftTraversal
    leftTravesal(root->left);
    //leafNodeTraversal
    leafNodeTraversal(root);
    // rightTraversal
    rightTravesal(root->right);
}

int main(){
    cout<<"enter the root Node:"<<endl;
    int data;
    cin>>data;
    Node* root=buildTree(data);
    // printTopView(root);
    
   BoundaryTraversal(root);
}
