// GFG

// broute force
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void Inorder1(Node* root1,vector<int>&ans){
        if(root1==NULL)return;
        Inorder1(root1->left,ans);
        ans.push_back(root1->data);
        Inorder1(root1->right,ans);
    }
    void Inorder2(Node* root2,vector<int>&ans){
        if(root2==NULL)return;
        Inorder2(root2->left,ans);
        ans.push_back(root2->data);
        Inorder2(root2->right,ans);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int>ans1;
        Inorder1(root1,ans1);
        vector<int>ans2;
        Inorder2(root2,ans2);
        vector<int>ans3=ans1;
        for(int i=0; i<ans2.size(); i++){
            ans3.push_back(ans2[i]);
        }
       
        sort(ans3.begin(),ans3.end());
       return ans3;
        }
