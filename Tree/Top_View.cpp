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
void printTopView(Node* root){
    if(root == NULL){
        return;
    }
   map<int,int>mp;
    queue<pair<Node*,int>>q;
    // Push root node and horizontal distance of root node
      q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int>temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;
       
        if(mp.find(hd) == mp.end()){
            // The above condition tells that entry is not present
            // Create the entry
            mp[hd] = frontNode->data;
        }
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
for(auto it:mp){
    cout<<it.first<<"->"<<it.second<<" ";
}
}

int main(){
    cout<<"enter the root Node:"<<endl;
    int data;
    cin>>data;
    Node* root=buildTree(data);
    // printTopView(root);
    printBottomView(root);
}
