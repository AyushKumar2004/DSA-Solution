#include <bits/stdc++.h>
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

node* rotateNnodes(node* head,int k){

    if(head==NULL || k==0){
        return head;
    }

    int cnt=1;
    node* temp=head;
    while(temp->next!=NULL && cnt<k){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        return head;
    }

    node* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }

    node* newHead=temp->next;
    temp->next=NULL;
    newHead->prev=NULL;

    curr->next=head;
    head->prev=curr;

    return newHead;
}


int main(){

    node* head=NULL;
    node* tail=NULL;

    insertAtHead(head,tail,8);
    insertAtHead(head,tail,7);
    insertAtHead(head,tail,10);
    insertAtHead(head,tail,5);
    insertAtHead(head,tail,4);
    cout<<"doubly Linkedlist:"<<endl;
    print(head);
    cout<<"After rotating N nodes of linkedList:"<<endl;
    int k=2;
    node* temp=rotateNnodes(head,k);
    print(temp);
    

    return 0;
}