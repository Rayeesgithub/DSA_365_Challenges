//https://www.geeksforgeeks.org/problems/intersection-of-two-linked-list/1

  Node* findIntersection(Node* head1, Node* head2) {
        // code here
        unordered_map<int,bool>mp;
        Node* dummy=new Node(-1);
        Node* curr=dummy;
        Node* temp=head2;
        while(temp!=NULL){
            mp[temp->data]=true;
            temp=temp->next;
        }
        temp=head1;
        while(temp!=NULL){
            if(mp.find(temp->data)!=mp.end()){
                curr->next=new Node(temp->data);
                curr=curr->next;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
