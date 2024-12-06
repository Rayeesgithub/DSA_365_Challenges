// GFG
int inOrderSuccessor(Node *root, Node *x) {
        int sucess=-1;
        Node* curr=root;
        while(curr){
            if(curr->data > x->data){
               sucess=curr->data;
               curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
        return sucess;
    }
