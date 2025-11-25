//love bbar
https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1


#include<iostream>
using namespace std;
class Node{
 public:
 int data;
 Node* next;
 Node* prev;
 Node(){
   this->data=0; 
   this->next=NULL;
   this->prev=NULL;
 }
 Node(int data){
   this->data=data;
   this->next=NULL;
   this->prev=NULL;

 }
 
};
void print(Node* &head){
   Node* temp=head;
   while(temp!=nullptr){
      cout<<temp->data<<" ";
      temp=temp->next;
   }
 }

int findLength(Node* &head){
   Node* temp=head;
   int len=0;
   while(temp!=nullptr){
      len++;
      temp=temp->next;
   }
   return len;
}
void insertAtHead(Node* &head,Node* &tail,int data){
    if(head==NULL){
      Node* newNode=new Node(data);
      head=newNode; 
      tail=newNode;
      return;
    }
    else{
      Node* newNode=new Node(data);
      newNode->next=head;
      head->prev=newNode;
     head=newNode;
    }
}
void insertAtTail(Node* &head,Node* &tail,int data){
   if(head==nullptr){
      Node* newNode=new Node(data);
      head=newNode;
      tail=newNode;
   }
   else{
      Node* newNode=new Node(data);
      tail->next=newNode;
      newNode->prev=tail;
      tail=newNode;
   }
}
void InsertAtanyPosition(Node* &head, Node* &tail, int data, int position) {

    // 🔹 Case 1: Insert at head (position = 0)
    if(position == 0) {
        InsertAtHead(head, tail, data);
        return;   // must return after inserting
    }

    // 🔹 Get length of the list
    int len = getLength(head);

    // 🔹 Case 2: Insert at tail (position >= len)
    if(position >= len) {
        InsertAtTail(head, tail, data);
        return;   // missing return (important)
    }

    // 🔹 Now inserting in middle of list

    // We need to stop at (position - 1)
    int i = 0;
    Node* prevNode = head;

    // Move prevNode to one position before insertion point
    while(i < position - 1) {
        prevNode = prevNode->next;
        i++;
    }

    // curr = node currently at "position"
    Node* curr = prevNode->next;

    // Create new node
    Node* newNode = new Node(data);

    // 🔹 Connect newNode between prevNode and curr:

    prevNode->next = newNode; // prev -> new node
    newNode->prev = prevNode; // new -> prev link

    newNode->next = curr;     // new -> curr
    curr->prev = newNode;     // curr -> new
}

int main(){
   Node* head=NULL;
   Node* tail=NULL;
   insertAtHead(head,tail,10);
   insertAtHead(head,tail,20);
   insertAtHead(head,tail,30);
   insertAtHead(head,tail,40);
   insertAtTail(head,tail,50);
   insertAtPoisition(head,tail,101,1);
   print(head);
}
