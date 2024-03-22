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
    cout<<endl;
}

void insertAtHead(node* &tail,int element,int key){
    if(tail==NULL){
        node* temp=new node(key);
        temp->next=temp;
        tail=temp;
        return;
    }
    else{
        node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        node* newNode=new node(key);
        newNode->next=curr->next;
        curr->next=newNode;
    }
}

void deleteNode(node* &tail, int key)
{

    node* prev=tail;
    node* temp=prev->next;
    while(temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    if(temp==tail){
        tail=prev;
    }
    if(temp==prev){
        tail=NULL;
    }
    temp->next=NULL;
    delete temp;
}

/* Function to reverse the linked list */
 void reverse(node* &tail)
{
    if((tail)==NULL || (tail)->next==tail){
        return;
    }
    node* temp=tail;
    node* prev=NULL;
    node* forward=NULL;
    while(forward!=tail){
        forward=temp->next;
        temp->next=prev;
        prev=temp;
        temp=forward;
    }
    temp->next=prev;
    tail=prev;
}


int main()
{   
    node* curr=NULL;
    node* tail=NULL;

    insertAtHead(tail,5,4);
    insertAtHead(tail,4,5);
    insertAtHead(tail,5,6);
    insertAtHead(tail,6,7);
    insertAtHead(tail,7,8);
    print(tail);
    cout<<"after deleting the node:"<<endl;
    deleteNode(tail,5);
    print(tail);
    cout<<"reverse of the linkedList:"<<endl;
    reverse(tail);
    print(tail);
	return 0;
}