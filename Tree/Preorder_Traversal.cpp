
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
void PreOrder(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";

    // left call
    PreOrder(root->left);
    PreOrder(root->right);
 }
