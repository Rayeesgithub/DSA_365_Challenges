
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
  Node* InorderToBST(int inorder[],int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    int element=inorder[mid];
   Node* root=new Node(element);
    root->left=InorderToBST(inorder,s,mid-1);
    root->right=InorderToBST(inorder,mid+1,e);
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
    // Node* root=NULL;
    // cout<<"enter the elemnt is:";
    // TakeInput(root);
    // LevelOrderTraversal(root);
    
    int inorder[]={10,20,30,40,50,60,70,80};
    int s=0; int e=7; 
   Node* root=InorderToBST(inorder,s,e);
    LevelOrderTraversal(root);
 }
