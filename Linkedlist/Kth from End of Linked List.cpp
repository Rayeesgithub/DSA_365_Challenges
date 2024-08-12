// love babbar
https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

//approach1
void  getElem(Node* &head,int &k,int &ans){
       if(head==0) return;
       getElem(head->next,k,ans);
       k--;
       if(k==0){
           ans=head->data;
       }
   }
    int getKthFromLast(Node *head, int k) {
        // Your code here
        int ans=-1;
        getElem(head,k,ans);
        return ans;
    }

//approach2
  int getLen(Node* &head){
         int len=0;
         Node* temp=head;
         while(temp!=NULL){
             temp=temp->next;
             len++;
         }
         return len;
     }
    int getKthFromLast(Node *head, int k) {
        // Your code here
      
        int len=getLen(head);
        Node* temp=head;
        // The position from the start that corresponds to the k-th from last
    int targetIndex = len - k;
 // Check if k is out of bounds
    if (k > len || k <= 0) {
        return -1; // k is invalid
    }

    int currentIndex = 0;
    while (temp != NULL) {
        // When the current index matches the target index, return the value
        if (currentIndex == targetIndex) {
            return temp->data;
        }
        temp = temp->next;
        currentIndex++;
    }

    return -1; // In case something goes wrong
    }
