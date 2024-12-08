// love sheet
class Solution{
  public:
   void checkDead(Node* root,bool &ans,unordered_map<int,bool>&visited){
     if(root==NULL) return;
     visited[root->data]=1;
     if(root->left==NULL && root->right==NULL){
         int lh=root->data-1 ==0 ? root->data :root->data-1;
         int rh=root->data+1;
         if(visited.find(lh)!=visited.end() && visited.find(rh)!=visited.end()){
             ans=true;
             return;
         }
     }
     checkDead(root->left, ans, visited);
     checkDead(root->right, ans, visited);
   }
    bool isDeadEnd(Node *root)
    {
        bool ans=false;
        unordered_map<int,bool>mp;
        checkDead(root,ans,mp);
        return ans;
    }
