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

 void InorderTravesal(Node* root){
    if(root==NULL){
        return;
    }

    //left call
    InorderTravesal(root->left);
    // root elemnt 
    cout<<root->data<<" ";

    InorderTravesal(root->right);

}
