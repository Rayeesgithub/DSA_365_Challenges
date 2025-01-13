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
// Function to print the Linked List
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
   
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    int data,choice;
    while(true){
        cout<<"1. Insert at Head"<<endl;
        cout<<"2. print"<<endl;
        cout<<"3. exit"<<endl;
        cout<<"enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: 
            cout << "Enter data to insert at head: ";
             cin >> data; 
             InsertAtHead(head, tail, data);
              break;

            case 2:
            cout<<"print Elemnt:";
            print(head);
            break;
            cout<<endl;
            case 3:
            return 0;
            default:
            cout<<"your Invalid Choice:";
        }
    }
}
