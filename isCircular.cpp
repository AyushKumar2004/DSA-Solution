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

bool isCircular(node *head)
{
   node* temp=head->next;
   if(head==NULL) return 0;
   while(temp!=head && temp!=NULL){
       temp=temp->next;
   }
   if(temp==NULL){
       return 0;
   }else{
       return 1;
   }
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

    if(isCircular(tail)){
        cout<<"Yes,The given linkedList is Circular."<<endl;
    }else{
        cout<<"No,The given linkedList is not circular"<<endl;
    }

	return 0;
}