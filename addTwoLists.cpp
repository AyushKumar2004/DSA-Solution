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
        if(head==NULL){
            return NULL;
        }
        node* curr=head;
        node* prev=NULL;
        reverse(head,curr,prev);
        return head;
}
    
node* addTwoLists(node* num1, node* num2)
    {
        node* prev=NULL;
        node* head=NULL;
        int carry=0;
        num1=reverseLL(num1);
        num2=reverseLL(num2);
        node* temp1=num1;
        node* temp2=num2;
        while(temp1!=NULL && temp2!=NULL){
            node* newNode=new node(temp1->data+temp2->data+carry);
            if(prev!=NULL){
            prev->next=newNode;
            prev=newNode;
            }
            if(prev==NULL && head==NULL){
                head=newNode;
                prev=newNode;
            }
            if(newNode->data<10){
                carry=0;
            }else{
                carry=1;
                newNode->data=(newNode->data)%10;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        while(temp1!=NULL){
            node* newNode=new node(temp1->data+carry);
            if(prev!=NULL){
            prev->next=newNode;
            prev=newNode;
            }
            if(prev==NULL && head==NULL){
                head=newNode;
                prev=newNode;
            }
            if(newNode->data<10){
                carry=0;
            }else{
                carry=1;
                newNode->data=(newNode->data)%10;
            }
            temp1=temp1->next;
        }
        
        while(temp2!=NULL){
            node* newNode=new node(temp2->data+carry);
            if(prev!=NULL){
            prev->next=newNode;
            prev=newNode;
            }
            if(prev==NULL && head==NULL){
                head=newNode;
                prev=newNode;
            }
            if(newNode->data<10){
                carry=0;
            }else{
                carry=1;
                newNode->data=(newNode->data)%10;
            }
            temp2=temp2->next;
        }
        
        while(carry){
            node* newNode=new node(carry);
            if(prev!=NULL){
            prev->next=newNode;
            prev=newNode;
            }
            if(newNode->data<10){
                carry=0;
            }else{
                carry=1;
                newNode->data=(newNode->data)%10;
            }
            carry=carry/10;
        }
        
        head=reverseLL(head);
        return head;
    }


int main()
{   
    node* head1=NULL;
    node* tail1=NULL;

    node* head2=NULL;
    node* tail2=NULL;
    insertAtHead(tail1,head1,4);
    insertAtHead(tail1,head1,6);
    insertAtHead(tail1,head1,8);
    insertAtHead(tail1,head1,4);
    insertAtHead(tail1,head1,2);
    cout<<"first linkedList:"<<endl;
    print(head1);

    insertAtHead(tail2,head2,4);
    insertAtHead(tail2,head2,7);
    insertAtHead(tail2,head2,8);
    insertAtHead(tail2,head2,5);
    insertAtHead(tail2,head2,2);
    cout<<"second LinkedList:"<<endl;
    print(head2);
    cout<<endl;

    cout<<"New linkedList after adding:"<<endl;

    node* temp=addTwoLists(head1,head2);

    print(temp);
    

	return 0;
}