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

void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void insertAtHead(node* &tail,node* &head,int data){
    if(tail==NULL){
        node* temp=new node(data);
        head=temp;
        tail=temp;
        return;
    }
    node* temp=new node(data);
    temp->next=head;
    head=temp;
}

node* moveToFront(node* head){
        if(head==NULL){
            return NULL;
        }
        node* temp=head;
        if(temp->next==NULL){
            return temp;
        }
        while(temp!=NULL){
            if(temp->next->next==NULL){
                node* LastNode=temp;
                temp=LastNode->next;
                LastNode->next=NULL;
                break;
            }
            temp=temp->next;
        }
       
        temp->next=head;
        head=temp;
        return head;
    }


int main()
{   
    node* head=NULL;
    node* tail=NULL;

    insertAtHead(tail,head,4);
    insertAtHead(tail,head,6);
    insertAtHead(tail,head,8);
    insertAtHead(tail,head,4);
    insertAtHead(tail,head,2);
    cout<<"unrotated linked list:"<<endl;
    print(head);
    cout<<endl;

    cout<<"rotated linked list with 90 degree:"<<endl;

    node* temp=moveToFront(head);

    print(temp);
    

	return 0;
}