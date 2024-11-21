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

void PostOrderTraversal(Node* root){
    if(root==NULL) {
        return ;
    }

    // left
    PostOrderTraversal(root->left);

    PostOrderTraversal(root->right);

    cout<<root->data<<" ";
 }
