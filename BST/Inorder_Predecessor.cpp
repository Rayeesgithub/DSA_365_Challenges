
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
   Node* Inorder_Predecessor(Node* root,int p){
    Node* pred=0;
    Node* curr=root;
    while(curr){
   if(curr->data < p){
     pred=curr;
     curr=curr->right;
   }
   else{
    curr=curr->left;
   }
    }
    return pred;
   }
 int main(){
    Node* root=NULL;
    cout<<"enter the elemnt is:";
    TakeInput(root);
    cout<<"Level order Traversal is:";
    LevelOrderTraversal(root);
    int p=8;
    cout<<endl;
   Node* ans=Inorder_Predecessor(root,p);
   cout<<"Inorder Precessor is:"<<ans->data;
 }
