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
Node *buildTree(int data)
{
  if(data==-1){
    return NULL;
  }

  Node* root=new Node(data);

  int leftData;
  cout<<"enter the left of data:";
  cin>>leftData;
   root->left=buildTree(leftData);
  int rightData;
  cout<<"enter the rightData:";
  cin>>rightData;
   root->right=buildTree(rightData);

   return root;
}

 vector<int> diagonal(Node *root)
{
  vector<int>ans;
  if(root==NULL) return ans;
  
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
       Node* temp=q.front();
       q.pop();
       while(temp){
           ans.push_back(temp->data);
           if(temp->left){
               q.push(temp->left);
           }
           temp=temp->right;
       }
     
   } 
   return ans;
}

int main(){
    
    int data;
    cout<<"enter the root Node:"<<endl;
    cin>>data;
    Node* root=buildTree(data);
    // printTopView(root);
    vector<int>ans=diagonal(root);

    for(int i=0; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
   
}
