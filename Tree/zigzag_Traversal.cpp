
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
    // base case
    if(data==-1){
        return NULL;
    }

    // create a newNodee
      Node *root = new Node(data);
      int leftData;
      cout<<"enter the left Data:";
      cin>>leftData;
       cout<<endl;
      root->left=buildTree(leftData);
      
      int rightData;
      cout<<"enter the rightdata:";
      cin>>rightData;

      root->right=buildTree(rightData);

      return root;
 }
 vector<vector<int>>zigzag(Node* root){
     vector<vector<int>>ans; // Stores the final zigzag traversal result
     if(root==NULL) return ans;
     bool leftToRight=true; // Direction flag: true for left-to-right, false for right-to-left
     queue<Node*>q;
     q.push(root);  // Start with the root node
     while(!q.empty()){
           int size = q.size(); // Number of nodes in the current level
        vector<int> level(size); // Temporary vector to store values at the current level
         for (int i = 0; i < size; i++) {
         Node * temp=q.front();
         q.pop();
         int index=leftToRight ? i : size-i-1;  // Determine the index based on the current direction
         level[index]=temp->data;    // Add the node's value to the appropriate index in the level vector
        
           if(temp->left){      // Add the left child to the queue (if it exists)
             q.push(temp->left);
         }
         
         if(temp->right){          // Add the right child to the queue (if it exists)
             q.push(temp->right);
         }
         }
         ans.push_back(level);      // Add the current level's values to the final result
         
         leftToRight=!leftToRight;     // Toggle the direction for the next level
     }
     return ans;
 }
int main(){
    Node* root;
    int data;
    cout<<"enter the date for Root Node:";
    cin>>data;
    root=buildTree(data);
    vector<vector<int>>ans=zigzag(root);
    cout<<"zig-zag Traversal is:";
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
    }
    
    
    
    
    
}
