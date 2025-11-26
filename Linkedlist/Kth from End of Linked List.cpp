// love babbar
https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

Input: LinkedList: 1->2->3->4->5->6->7->8->9, k = 2
Output: 8
Explanation: The given linked list is 1->2->3->4->5->6->7->8->9. The 2nd node from end is 8.



// Function to calculate total length of linked list
int getLen(Node* &head){
    int len = 0;
    Node* temp = head;

    // Traverse entire list and count the nodes
    while(temp != NULL){
        temp = temp->next;
        len++;                 // increase length
    }
    return len;
}

int getKthFromLast(Node* head, int k) {
    // First find total length of the list
    int len = getLen(head);

    Node* temp = head;

    // Traverse the list until temp points to the Kth node from end
    while(temp != NULL){

        // When remaining length equals k → this node is the Kth from last
        if(len == k){
            return temp->data;   // return the value
        }
        else{
            len--;               // decrease remaining length
            temp = temp->next;   // move to next node
        }
    }

    return -1;  // If k is larger than length → invalid case
}
       
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

