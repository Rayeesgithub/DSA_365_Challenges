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
   // basecase 
   if(data==-1){
    return NULL;
   }

   Node* root=new Node(data);
    // left
    int leftData;
    cout<<"enter the Left Data:";
    cin>>leftData;

     root->left=buildTree(leftData);

     // right
     int rightData;
     cout<<"enter thr right Data:";
     cin>>rightData;

     root->right=buildTree(rightData);

     return root;


 }
 
 void LevelOrder(Node* root) {
    // Base case: If the root is NULL, return (no tree to traverse)
    if (root == NULL) {
        return;
    }

    // Create a queue to store nodes at each level
    queue<Node*> q;
    // Start with the root node and enqueue it
    q.push(root);
    // q.push(NULL);
    // Continue the traversal until the queue becomes empty
    while (!q.empty()) {
        // Dequeue the front node from the queue
        Node* temp = q.front();
        q.pop();

       // if (temp == NULL)
       //  {
       //      // go to the next line
       //      cout << endl;
       //      // Marking for next level
       //      if (!q.empty())
       //      {
       //          q.push(NULL);
       //      }
       //  }
       //  // Print the data of the current node
       //  else{

      
             cout << temp->data << " ";

        // Enqueue the left child if it exists
        if (temp->left != NULL) {
            q.push(temp->left);
        }

        // Enqueue the right child if it exists
        if (temp->right != NULL) {
            q.push(temp->right);
        }
        }
       
    
}

int main(){
    Node* root;
    int data;
    
    cout<<"enter the date for Root Node:";
    cin>>data;
    root=buildTree(data);
    cout<<"Level Order Traversal:";
    LevelOrder(root);
}
