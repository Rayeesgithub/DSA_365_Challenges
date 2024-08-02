// basic love babbar

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data=data;
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
int main(){
    Node* first=new Node(1);
    Node*second=new Node(2);
    Node* third=new Node(3);

    first->next=second;
    second->next=third;
    cout<<"print all lilnkedlist"<<endl;
    print(first);
}
