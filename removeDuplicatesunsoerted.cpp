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

node * removeDuplicates( node *head) 
{
    if(head==NULL){
        return NULL;
    }
    node* prev=head;
    node* curr=head;
    unordered_set<int> seen;
    while(curr!=NULL){
        if(seen.find(curr->data)!=seen.end()){
            prev->next=curr->next;
            delete curr;
            curr=prev->next;
        }else{
            seen.insert(curr->data);
            prev=curr;
            curr=curr->next;
        }
    }
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
    cout<<"unsorted linked list:"<<endl;
    print(head);
    cout<<endl;

    cout<<"unsorted linked list without duplicates:"<<endl;

    node* temp=removeDuplicates(head);

    print(temp);
    

	return 0;
}