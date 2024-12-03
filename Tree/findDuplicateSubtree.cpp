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
      vector<Node*>ans;
      unordered_map<string,int>subTree;
      string preorder(Node* root){
        if(root==NULL){
            return "N";
        }
        string curr=to_string(root->data);

        string ls=preorder(root->left);
        string rs=preorder(root->right);

        string s=curr+","+ls+","+rs;

        if(subTree.find(s)!=subTree.end()){
            if(subTree[s]==1){
                ans.push_back(root);
                subTree[s]++;
            }
        }
        else{
            subTree[s]=1;
        }
        return s;
      }
int main(){
    Node* root;
    int data;
    cout<<"enter the date for Root Node:";
    cin>>data;
    root=buildTree(data);
    
  preorder(root);
   for(auto i=0; i<ans.size(); i++){
      cout<<ans[i]->data<<" ";
  }    
}
