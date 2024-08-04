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
void insertAtPoisition(Node* &head,Node* &tail,int data,int position){
    if(position == 0) {
                insertAtHead(head, tail , data);
                return;
        }
   int len=findLength(head);
   if(position>=len){
    insertAtTail(head, tail, data);
                return;
   }
   int i=1;
   Node* prevNode=head;
   while(i<position-1){
      prevNode=prevNode->next;
      i++;
   }
   Node* curr=prevNode->next;

   Node* newNode=new Node(data);
    prevNode -> next = newNode;
   newNode->prev=prevNode;
   newNode->next=curr;
   curr->prev=newNode;
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
