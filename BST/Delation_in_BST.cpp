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

 int findMax(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
 }
 Node* DeleateNode_BST(Node* root,int target){
    if(root==NULL){
     return root;
    }

    if(root->data==target){
     
     //case1->both left & right child is Null
     if(root->left==NULL && root->right==NULL){
       return NULL;
     }
     else if(root->left==NULL && root->right!=NULL){
        Node* rightchild=root->right;
        return rightchild;
     }
     else if(root->left!=NULL && root->right==NULL){
        Node* leftChild=root->left;
        return leftChild;
     }
     else{
        int inorderPre=findMax(root->left);
        root->data=inorderPre;
        root->left=DeleateNode_BST(root->left,inorderPre);
        return root;
     }
    }
    else if(root->data< target){
        root->right=DeleateNode_BST(root->right,target);
    }
    else{
     root->left=DeleateNode_BST(root->left,target);
    }
    return root;
 }
    void LevelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
   }
 int main(){
    Node* root=NULL;
    cout<<"enter the elemnt is:";
    TakeInput(root);
    // LevelOrderTraversal(root);
    int target=6;
  DeleateNode_BST(root,target);
   LevelOrderTraversal(root);
   
 }
