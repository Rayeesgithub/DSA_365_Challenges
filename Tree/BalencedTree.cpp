
// Broute force-> Time-Complxity 0(N^2)
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
bool BalencedTree(Node * root){
if(root==NULL){
    return true;
}
int lh=height(root->left);
int rh=height(root->right);
if(abs(lh-rh)<=1) return true;
bool ans1=BalencedTree(root->left);
bool ans2= BalencedTree(root->right);
bool res=false;
if(ans1 && ans2){
    res=true;
}
return res;
}
int main(){
   Node* root;
    int data;
    cout<<"enter the date for Root Node:";
    cin>>data;
    root=buildTree(data);
int ans=height(root);
  if(BalencedTree(root)){
    cout<<"Tree is Balenced:";
  }
  else{
    cout<<"Tree is Not Balenced:";
  }
}






// optimal approach-> Time-Complxity 0(N)
bool Balenced=true;
int height(TreeNode* root){
    if(root==NULL) return 0;

    int lh=height(root->left);
    int rh=height(root->right);
    if(Balenced && abs(lh-rh)>1){
       Balenced=false;
    }
    return max(lh,rh)+1;
}
    bool isBalanced(TreeNode* root) {
       if(root==NULL) return true;
       int ans=height(root);
       return Balenced;
    }

