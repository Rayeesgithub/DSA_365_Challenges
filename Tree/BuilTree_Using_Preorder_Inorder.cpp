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
Node* makeTree(int inorder[],int preorder[],int size,int &preIndex,int inorderStart,int inorderEnd){
    //basecase
    if(preIndex>=size || inorderStart>inorderEnd){
        return NULL;
    }
 int element=preorder[preIndex++];
 Node* root=new Node(element);

 int pos=findPos(inorder,size,element);
root->left=makeTree(inorder,preorder,size,preIndex,inorderStart,pos-1);
root->right=makeTree(inorder,preorder,size,preIndex,pos+1,inorderEnd);

return root;
}


// Node* buildTree(int inorder[],int preorder[],int size,int &preIndex,int inorderStart,int inorderEnd,unordered_map<int,int>&mapping){
//     // Base case
//     if(preIndex >= size || inorderStart > inorderEnd){
//         // Insert NULL
//         return NULL;
//     }
//     // Find the root node of the tree and we get this from preorder traversal
//     int element = preorder[preIndex++];
//     // Create root node for this element
//     Node* root = new Node(element);
//     // Find the root element in the inorder
//     // int pos = findPos(inorder,size,element);
//     int pos = mapping[element];
//     // Solving left part
//     root->left = buildTree(inorder,preorder,size,preIndex,inorderStart,pos-1,mapping);
//     // Solving right part
//     root->right = buildTree(inorder,preorder,size,preIndex,pos+1,inorderEnd,mapping);
//     // return root node 
//     return root;
// }
// void createMapping(unordered_map<int,int>&mapping,int inorder[],int n){
//     for(int i = 0;i<n;i++){
//         mapping[inorder[i]] = i;
//     }
// }
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

    int inorder[] = {3,1,4,5,2};
    int preorder[] = {5,1,3,4,2};
    int size=5;
    int inorderStart=0;
    int inorderEnd=size-1;
    int preIndex=0;  
    cout<<"Built Tre usinf Inorder ans Preorder:";

    root=makeTree(inorder,preorder,size,preIndex,inorderStart,inorderEnd);
    //   createMapping(mapping,inorder,size);
    // cout<<"Building tree"<<endl;
    // Node* root = buildTree(inorder,preorder,size,preIndex,inorderStart,inorderEnd,mapping);

    levelOrder(root);
}
 
