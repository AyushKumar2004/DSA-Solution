#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is deleted of node with data:"<<val<<endl;
    }
};

void print(node* &tail){
    node* temp=tail;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail);
}

void insertAtHead(node* &tail,node* &curr,int data){
    if(tail==NULL){
        node* temp=new node(data);
        temp->next=temp;
        tail=temp;
        curr=temp;
        return;
    }
    node* temp=new node(data);
    temp->next=curr->next;
    curr->next=temp;
    curr=temp;
}

node* getMiddle(node* head){
    node* slow=head;
    node* fast=head->next;
    while(fast!=head && fast->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

void splitList(node *head, node* &head1_ref, node* &head2_ref)
{   
    if (head == NULL || head->next == NULL) {
        head1_ref = head;
        head2_ref = NULL;
        return;
    }
    node* mid=getMiddle(head);
    head1_ref=head;
    head2_ref=mid->next;
    
    mid->next=head;
    node* temp=head2_ref;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=head2_ref;
}


int main()
{   
    node* curr=NULL;
    node* tail=NULL;

    insertAtHead(tail,curr,4);
    insertAtHead(tail,curr,5);
    insertAtHead(tail,curr,6);
    insertAtHead(tail,curr,7);
    insertAtHead(tail,curr,8);
    print(tail);
    cout<<endl;

    node* head1_ref=NULL;
    node* head2_ref=NULL;
    splitList(tail,head1_ref,head2_ref);
    cout<<"the first splitted linkedlist:"<<endl;
    print(head1_ref);
    cout<<endl;
    cout<<"The second splitted linkedList:"<<endl;
    print(head2_ref);

	return 0;
}