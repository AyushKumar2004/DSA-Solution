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

node* solve(node* head){
        if(head==NULL){
            return NULL;
        }
        
        node* fast=head;
        node* slow=head;
        
        while(fast!=NULL && slow!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
            if(slow==fast){
                return slow;
            }
        }
        return NULL;
    } 
     
int findFirstNode(node* head)
{
    node* temp=solve(head);
    if(temp==NULL){
        return -1;
    }
    node* slow=head;
    while(temp!=slow){
        slow=slow->next;
        temp=temp->next;
    }
    return slow->data;
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

    cout<<findFirstNode(tail);
    

	return 0;
}