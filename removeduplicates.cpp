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

node *removeDuplicates(node *head)
{   
    if(head==NULL){
        return NULL;
    }
    node* curr=head;
    while(curr!=NULL){
        if(curr->next!=NULL && curr->data==curr->next->data){
            node* nextNext=curr->next->next;
            node* deleteNode=curr->next;
            delete deleteNode;
            curr->next=nextNext;
        }else{
            curr=curr->next;
        }
    }
    return head;
}


int main()
{   
    node* head=NULL;
    node* tail=NULL;

    insertAtHead(tail,head,6);
    insertAtHead(tail,head,6);
    insertAtHead(tail,head,4);
    insertAtHead(tail,head,4);
    insertAtHead(tail,head,2);
    cout<<"sorted linked list:"<<endl;
    print(head);
    cout<<endl;

    cout<<"sorted linked list without duplicates:"<<endl;

    node* temp=removeDuplicates(head);

    print(temp);
    

	return 0;
}