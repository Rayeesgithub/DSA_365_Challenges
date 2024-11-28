
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
 int sumTree(Node* root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            int temp=root->data;
            root->data=0;
            return temp;
        }
        
        int leftSum=sumTree(root->left);
        int rightSum=sumTree(root->right);
        
        int temp=root->data;
        root->data=leftSum+rightSum;
        return root->data+temp;
    }
    void printLevelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        cout << node->data << " "; // Print the current node's value

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}
int main(){
    Node* root;
    int data;
    cout<<"enter the date for Root Node:";
    cin>>data;
    root=buildTree(data);
  
    sumTree(root);
    cout<<"Printing the sum of root Node"<<" ";
    
    printLevelOrder(root);
    
    
    
}
