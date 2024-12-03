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
 
   void Inorder(Node* root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
   }
   void Preorder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
   }
   void PostOrder(Node* root){
    if(root==NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
   }
 int main(){
    Node* root=NULL;
    cout<<"enter the elemnt is:";
    TakeInput(root);
    // LevelOrderTraversal(root);
    cout<<endl;
    cout<<"Inorder Traversal is:";
    Inorder(root);
    cout<<"PreOrder Traversal is:";
    Preorder(root);
    cout<<endl;
    cout<<"PostOrder Traversal is:";
    PostOrder(root);


 }
