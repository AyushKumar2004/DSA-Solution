#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    ~node(){
        int val=this->data;
        if(this->next!=NULL || this->prev!=NULL){
            delete next;
            delete prev;
            this->next=NULL;
            this->prev=NULL;
        }
        cout<<"Meemory is free for the data with node:"<<val<<endl;
    }
};

void insertAtHead(node* &head,node* &tail,int data){
    if(head==NULL){
        node* newNode=new node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    node* newNode=new node(data);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}

void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* reverseDLL(node * head)
    {
        node* back=NULL;
        node* forward=NULL;
        node* curr=head;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=back;
            curr->prev=forward;
            back=curr;
            curr=forward;
        }
        return back;
    }

int main(){

    node* head=NULL;
    node* tail=NULL;

    insertAtHead(head,tail,4);
    insertAtHead(head,tail,5);
    insertAtHead(head,tail,6);
    insertAtHead(head,tail,7);
    insertAtHead(head,tail,8);
    cout<<"doubly Linkedlist:"<<endl;
    print(head);

    cout<<"reverse the doubly linkedList:"<<endl;
    node* temp=reverseDLL(head);
    print(temp);

    return 0;
}