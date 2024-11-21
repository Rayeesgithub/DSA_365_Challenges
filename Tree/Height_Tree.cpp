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

 int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int leftHeight=height(root->left);

    int rightHeight=height(root->right);

    int ans=max(leftHeight,rightHeight)+1;

    return ans;
 }
