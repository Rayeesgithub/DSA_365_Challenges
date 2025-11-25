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
void InsertAtTail(Node* head,Node* tail,int data){
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    else{
        Node* newNode=new Node(data);
        tail->next=newNode;
        tail=newNode;
    }
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
   Node* head=new Node(10);
 Node* tail=head;
InsertAtHead(head,tail,50);
  InsertAtHead(head,tail,40);
  InsertAtTail(head,tail,60);
 cout<<"printing Linklist"<<endl;
 Printing(head);
}
