
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
void findPath(Node* root, int targetSum, int& pathCount) {
    if (root == NULL) return;

    // Check if current node completes a path
    if (root->data == targetSum) {
        pathCount++;
    }

    // Recur for left and right subtrees with updated target
    findPath(root->left, targetSum - root->data, pathCount);
    findPath(root->right, targetSum - root->data, pathCount);
}

// Main function to count paths with the given sum
int pathSum(Node* root, int targetSum) {
    if (root == NULL) return 0;

    int pathCount = 0;
    // Check paths starting from the current node
    findPath(root, targetSum, pathCount);

    // Recur for left and right subtrees
    pathCount += pathSum(root->left, targetSum);
    pathCount += pathSum(root->right, targetSum);

    return pathCount;
}
int main(){
    Node* root;
    int data;
    cout<<"enter the date for Root Node:";
    cin>>data;
    root=buildTree(data);
   int targetSum=4;
    int ans=pathSum(root,targetSum);
    cout<<"the Number pathsum count is:"<<ans;
    
    
}
