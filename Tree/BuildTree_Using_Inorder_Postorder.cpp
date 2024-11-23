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
int findPos(int inorder[],int n,int elemnt){
    for(int i=0; i<n; i++){
        if(inorder[i]==elemnt){
            return i;
        }
    }
    return -1;
}
Node* makeTree(int inorder[],int preorder[],int size,int &postIndex,int inorderStart,int inorderEnd){
    //basecase
    if(postIndex<0 || inorderStart>inorderEnd){
        return NULL;
    }
 int element=preorder[postIndex--];
 Node* root=new Node(element);

 int pos=findPos(inorder,size,element);

root->right=makeTree(inorder,preorder,size,postIndex,pos+1,inorderEnd);
root->left=makeTree(inorder,preorder,size,postIndex,inorderStart,pos-1);
return root;
}

 void levelOrder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node* >q;
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
   Node* root;
    int data;
    // cout<<"enter the date for Root Node:";
    // cin>>data;
    // root=buildTree(data);

    int inorder[] = {40,20,10,50,30,60};
    int postOrder[] = {40,20,50,60,30,10};
    int size=6;
    int inorderStart=0;
    int inorderEnd=size-1;
    int postIndex=size-1;  
    cout<<"Built Tre usinf Inorder ans Preorder:";

    root=makeTree(inorder,postOrder,size,postIndex,inorderStart,inorderEnd);

    levelOrder(root);
}
 
