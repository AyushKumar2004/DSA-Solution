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

int getMiddle(node *head)
    {   
        
        node* fast=head;
        node* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }


int main()
{   
    node* head1=NULL;
    node* tail1=NULL;

    node* head2=NULL;
    node* tail2=NULL;
    
    insertAtHead(tail1,head1,8);
    insertAtHead(tail1,head1,5);
    insertAtHead(tail1,head1,2);
    insertAtHead(tail1,head1,3);
    insertAtHead(tail1,head1,6);
    insertAtHead(tail1,head1,1);
    insertAtHead(tail1,head1,9);
    cout<<"LinkedList :"<<endl;
    print(head1);
    cout<<endl;
    cout<<"Middle of the linkedList:";
    cout<<getMiddle(head1);


	return 0;
}