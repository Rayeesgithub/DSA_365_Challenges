// lve babbar
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
void print(Node* &head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } 
    while (temp != head);
    cout << endl;
}

int findLength(Node* head) {
    if (head == nullptr) return 0;
    
    int length = 0;
    Node* temp = head;
    do {
        length++;
        temp = temp->next;
    } while (temp != head);
    
    return length;
}
void insertAtHead(Node* &head,Node* &tail,int data){
    Node* temp=new Node(data);
   if(head==NULL){
    
      head=temp;
      tail=temp;
        temp->next = head; // Point to itself
        return;
   }
   
     else{
       tail->next=temp;
      temp->next=head;
      head=temp;
     }
   
}
void insertAtTail(Node* &head,Node* &tail,int data){
    Node* newNode = new Node(data);
    
      if(head==NULL){
         head=newNode;
         tail=newNode;
      }
      else{
         tail->next=newNode;
         newNode->next=head;
         tail=newNode;
      }
}
void insertAtPosition(Node* &head,Node* &tail,int data,int pos){
   Node* newNode=new Node(data);
  if(head==NULL){
         head=newNode;
         tail=newNode;
      }
      if(pos==1){
         insertAtHead(head,tail,data);
         return;
      }
      int len=findLength(head);
      if(pos>=len){
         insertAtTail(head,tail,data);
         return;
      }

     
      int i = 1;
    Node* prev = head;
    while (i < pos) {
        prev = prev->next;
        i++;
    }
    
    
    newNode->next = prev->next;
    prev->next = newNode;
}
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtTail(head,tail,80);
    insertAtPosition(head,tail,101,1);
    print(head); // Expected output: 40 30 20 10
}
