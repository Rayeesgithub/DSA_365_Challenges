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
  bool findTarget(Node* root,int target){
    if(root==NULL){
        return false;
    }

    if(root->data==target){
    return true;
    }

    bool leftans=findTarget(root->left,target);
    bool rightans=findTarget(root->right,target);

    return leftans|| rightans;
  }
 int main(){
    Node* root=NULL;
    cout<<"enter the elemnt is:";
    TakeInput(root);
    // LevelOrderTraversal(root);
     int target=9;
    if(findTarget(root,target)){
        cout<<"Target Elemnt is found"<<endl;
    }
    else{
        cout<<"Target Elemnt is Not found"<<endl;
    }


 }
