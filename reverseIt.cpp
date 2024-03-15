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

void insertAtHead(node* &head,node* &tail,int data){
    if(head==NULL){
        node* temp=new node(data);
        head=temp;
        tail=temp;
        return;
    }
    node* temp=new node(data);
    temp->next=head;
    head=temp;
}

node* reverseIt (node* head, int k)
    { 
        if(head==NULL){
            return NULL;
        }
        node* curr=head;
        node* prev=NULL;
        node* next=NULL;
        int cnt=0;
        while(curr!=NULL && cnt<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        
        if(next!=NULL){
            head->next=reverseIt(next,k);
        }
        return prev;
    }


int main()
{   
    node* head=NULL;
    node* tail=NULL;

    insertAtHead(head,tail,4);
    insertAtHead(head,tail,5);
    insertAtHead(head,tail,6);
    insertAtHead(head,tail,7);
    insertAtHead(head,tail,8);
    int k=3;
    print(head);
    cout<<endl;
    node* temp=reverseIt(head,k);

    cout<<"The reverse linked list:"<<endl;
    print(temp);

	return 0;
}