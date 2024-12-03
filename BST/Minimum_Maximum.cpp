// Apprach1-> Inorder Travesal
void Inorder(Node* root, vector<int>&ans){
    if(root==NULL){
        return;
    }
    Inorder(root->left,ans);
    ans.push_back(root->data);
    Inorder(root->right,ans);
  }
 int main(){
    Node* root=NULL;
    cout<<"enter the elemnt is:";
    TakeInput(root);
    // LevelOrderTraversal(root);
    vector<int>ans;
    
    Inorder(root,ans);
    cout<<"Minimum Elemnt is:"<<ans[0]<<endl<<"Maximum Elemnt is:"<<ans[ans.size()-1];

 }


//Optimal-Approach
int findMin(Node* root){
 Node* temp=root;
 while(temp->left!=NULL){
    temp=temp->left;
 }
 return temp->data;
 }
 int findMax(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
 }
 int main(){
    Node* root=NULL;
    cout<<"enter the elemnt is:";
    TakeInput(root);
    // LevelOrderTraversal(root);
   int minEle=findMin(root);
   cout<<"Minimum Elemnt is :"<<minEle;
   cout<<endl;
   int maxEle=findMax(root);
   cout<<"Maximum Elemnt is:"<<maxEle;
