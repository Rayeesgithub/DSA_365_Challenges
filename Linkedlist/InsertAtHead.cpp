//love babbar

#include<iostream>
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
// Function to print the linked list
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void InsertAtHead(Node* &head,int data){
   
    // step1 create a node
    Node* newNode=new Node(data);
    // step2 newnode ko head se attach
    newNode->next=head;
    //step 3 head ko newnode pr wapas
    head=newNode;


}
int main(){
    Node* head=NULL;
   InsertAtHead(head,10);
  InsertAtHead(head,20);
  InsertAtHead(head,30);
  InsertAtHead(head,40);
  InsertAtHead(head,50);
  cout<<"Printing all LinkedList"<<endl;
  print(head);
}
