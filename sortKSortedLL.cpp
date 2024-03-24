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

class compare{
    public:
    int operator()(node* &p1,node* &p2){
        return p1->data>p2->data;
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


node* sortKSortedLL(node* head,int k){
    if(head==NULL){
        return head;
    }

    node* newHead=NULL,*curr;

    priority_queue<node*,vector<node*>,compare> pq;

    for(int i=0;head!=NULL && i<=k;i++){
        pq.push(head);
        head=head->next;
    }

    while(!pq.empty()){
        if(newHead==NULL){
            newHead=pq.top();
            newHead->prev=NULL;
            curr=newHead;
        }else{
            curr->next=pq.top();
            pq.top()->prev=curr;
            curr=pq.top();
        }
        pq.pop();
        if(head!=NULL){
            pq.push(head);
            head=head->next;
        }
    }
    curr->next=NULL;
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
    cout<<"sort k sorted linkedList:"<<endl;
    node* temp=sortKSortedLL(head,2);
    print(temp);
    

    return 0;
}