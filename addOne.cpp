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

void reverse(node* &head,node* curr,node* prev){
        if(curr==NULL){
            head=prev;
            return;
        }
        node* forward=curr->next;
        reverse(head,forward,curr);
        curr->next=prev;
    }
    
node* reverseLL(node* head){
    node* curr=head;
    node* prev=NULL;
    reverse(head,curr,prev);
    return head;
}

node* addOne(node *head) 
{
    head=reverseLL(head);
    int carry=1;
    node* temp=head;
    while(temp!=NULL){
        temp->data=temp->data+carry;
        if(temp->data<10){
            carry=0;
            break;
        }else{
            carry=1;
            temp=temp->next;
        }
    }
    
    if(carry==1){
        node* newNode=new node(carry);
        head=reverseLL(head);
        newNode->next=head;
        return newNode;
    }
    head=reverseLL(head);
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
    cout<<"linked list before adding one:"<<endl;
    print(head);
    cout<<endl;

    cout<<"linkedList after adding one:"<<endl;

    node* temp=addOne(head);

    print(temp);
    

	return 0;
}