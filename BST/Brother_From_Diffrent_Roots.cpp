// Broute force
void Inorder1(Node* root1, vector<int>&ans){
        if(root1==NULL) return;
        
        Inorder1(root1->left,ans);
        ans.push_back(root1->data);
        Inorder1(root1->right,ans);
    }
    void Inorder2(Node* root2,vector<int>&ans){
        if(root2==NULL) return;
        Inorder2(root2->left,ans);
        ans.push_back(root2->data);
        Inorder2(root2->right,ans);
        
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
     vector<int>ans1;
     Inorder1( root1,ans1);
     vector<int>ans2;
     Inorder2( root2,ans2);
    int count=0;
      for(int i=0; i<ans1.size(); i++){
         for(int j=0; j<ans2.size(); j++){
            if(ans1[i]+ans2[j]==x){
               count++;
            } 
         } 
      }
      return count;
    }
