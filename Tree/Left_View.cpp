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
    // -1 data indicates that we have the leaf node (Base Case)
    if (data == -1)
    {
        return NULL;
    }
    // Create the root node and hence solved 1 case
    Node *root =new Node(data);
    // Recursion will handle
    int leftData;
    cout << "Enter the data for left child of " << data << endl;
    cin >> leftData;
    root->left = buildTree(leftData);
    int rightData;
    cout << "Enter the data for right child of " << data << endl;
    cin >> rightData;
    root->right = buildTree(rightData);
    return root;
}
void printLeftView(Node* root,vector<int>&ans,int level){
    if(root==NULL)return;

    // validate that is if level is equal answer size then store in answer
    if(ans.size()==level){
    ans.push_back(root->data);
    }

    // leftcall
    printLeftView(root->left,ans,level+1);

    // right call
    printLeftView(root->right,ans,level+1);
}

int main(){
    cout<<"enter the root Node:"<<endl;
    int data;
    cin>>data;
    Node* root=buildTree(data);
    // printTopView(root);
    // printBottomView(root);
    vector<int>ans;
    int level=0;
    printLeftView(root,ans,level);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}
