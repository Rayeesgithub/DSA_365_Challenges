//  loveBaar

#include<iostream>
using namespace std;
class Node{
 public:
 int data;
 Node* next;
 Node* prev;
 // Node(){
 //   this->data=0; 
 //   this->next=NULL;
 //   this->prev=NULL;
 // }
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
void insertAtHead(Node* &head, Node* &tail, int data) {

    // If list is empty
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Create new node
    Node* newNode = new Node(data);

    // Link new node to current head
    newNode->next = head;

    // Old head should point back to new node
    head->prev = newNode;

    // Update head to new node
    head = newNode;
}

int main(){
   Node* head=NULL;
   Node* tail=NULL;
   insertAtHead(head,tail,10);
   insertAtHead(head,tail,20);
   insertAtHead(head,tail,30);
   insertAtHead(head,tail,40);
   print(head);
}
