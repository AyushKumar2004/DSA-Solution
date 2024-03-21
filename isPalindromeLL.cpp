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
    }cout<<endl;
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

node* reverseLL(node* head){
        node* curr=head;
        node* prev=NULL;
        node* forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    
    node* getMiddle(node* head){
        node* slow=head;
        node* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    bool isPalindrome(node *head)
    {
       node* mid=getMiddle(head);
       node* head2=mid->next;
       mid->next=NULL;
       head2=reverseLL(head2);
       node* temp1=head;
       node* temp2=head2;
       while(temp1!=NULL && temp2!=NULL){
           if(temp1->data!=temp2->data){
               return false;
           }
           temp1=temp1->next;
           temp2=temp2->next;
       }
       return true;
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
    if(isPalindrome(head1)){
        cout<<"Yes,It is a palindrome."<<endl;
    }else{
        cout<<"No,it is not a palindrome"<<endl;
    }


	return 0;
}