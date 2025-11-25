#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
     Node(){
        this->data=0;
        this->next=NULL;
     }
     Node(int data){
        this->data=data;
        this->next=NULL;
     }
};
void InsertAtHead(Node* &head, Node* &tail,int data){
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    else{
        Node* newNode=new Node(data);
        newNode->next=head;
        head=newNode;
    }
}
// Insert new node at the TAIL (End)
void InsertAtTail(Node* &head, Node* &tail, int data) {

    // Case 1: If Linked List is empty
    if (head == NULL) {
        Node* newNode = new Node(data); // Create new node
        head = newNode;                 // Both head and tail will point to this node
        tail = newNode;
    }
    else {
        // Case 2: List already has nodes
        Node* newNode = new Node(data); // Create new node
        tail->next = newNode;           // Connect new node after current tail
        tail = newNode;                 // Update tail to new node
    }
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout<<endl;
   
}
int main(){
  Node* head = new Node(10); // First node
    Node* tail = head;         // Tail same as head initially

    InsertAtHead(head, tail, 50); // 50 -> 10
    InsertAtHead(head, tail, 40); // 40 -> 50 -> 10
    InsertAtTail(head, tail, 60); // 40 -> 50 -> 10 -> 60
 cout<<"printing Linklist"<<endl;
 Printing(head);
}
