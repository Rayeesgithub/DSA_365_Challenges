
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
 void convertToDLL(Node* root, Node* &head){
    if(root == NULL){
        return;
    }
    // Convert right subtree to linked list
    convertToDLL(root->right,head);
    // Attach the root node to right linked list
    root->right = head;
    // Attaching previous pointer
    if(head!=NULL)
        // To avoid NULL pointer exception
        head->left = root;
    // Update head
    head = root;
    // Convert left subtree to linked list
    convertToDLL(root->left,head);
 }
 void Printing(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
 }
 int main(){
    Node* root=NULL;
    cout<<"enter the elemnt is:";
    TakeInput(root);
    // cout<<"Level order Traversal is:";
    // LevelOrderTraversal(root);
   Node* head=NULL;
   convertToDLL(root,head);
   cout<<"Printing sorted";
   Printing(head);
 }
