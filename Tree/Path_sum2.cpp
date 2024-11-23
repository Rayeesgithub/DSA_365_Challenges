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

 void solve(Node* root,int targetSum, vector<vector<int>>&ans,int currSum,vector<int>path){
        if(root==NULL) return;

        //leafNode found
        if(root->left==NULL && root->right==NULL){
            path.push_back(root->data);
            currSum+=root->data;
            if(currSum==targetSum){
                ans.push_back(path);
            }
            return;
        }
         path.push_back(root->data);
            currSum+=root->data;
            solve(root->left,targetSum,ans,currSum,path);
            solve(root->right,targetSum,ans,currSum,path);
    }
int main(){
   Node* root;
    int data;
    cout<<"enter the date for Root Node:";
    cin>>data;
    root=buildTree(data);
        vector<vector<int>>ans;
        int currSum=0; int targetSum=0;
        vector<int>path;
        solve(root,targetSum,ans,currSum,path);
       for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans.size(); j++){
            cout<<ans[i][j]<<" ";
        }
       }
}
 
