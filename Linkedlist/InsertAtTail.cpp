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
    Node* head=NULL;
    Node* tail=NULL;
    int choice,data;
    while(true){
        cout<<"1. insert at Head"<<endl;
        cout<<"2. insert at Tail"<<endl;
        cout<<"3. print"<<endl;
        cout<<"4. exit"<<endl;
        cout<<"enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"enter Head Elements:";
            cin>>data;
            InsertAtHead(head,tail,data);
            break;

            case 2:
            cout<<"enter Tail Elemnts:";
            cin>>data;
            InsertAtTail(head,tail,data);
            break;
            case 3:
            print(head);
            break;
            cout<<endl;
            case 4:
            return 0;
            default:
            cout<<"your Invalid Choice:";
        }
    }
}
