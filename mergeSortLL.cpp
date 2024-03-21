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

 node* findMid(node* head){
        node* slow=head;
        node* fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    node* merge(node* left,node* right){
        
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        
        node* ans=new node(-1);
        node* temp=ans;
        
        while(left!=NULL && right!=NULL){
            if(left->data<right->data){
                temp->next=left;
                temp=left;
                left=left->next;
            }else{
                temp->next=right;
                temp=right;
                right=right->next;
            }
        }
        
        while(left!=NULL){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        
        while(right!=NULL){
            temp->next=right;
            temp=right;
            right=right->next;
        }
        
        ans=ans->next;
        return ans;
    }
    
    
    node* mergeSort(node* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        node* mid=findMid(head);
        node* left=head;
        node* right=mid->next;
        mid->next=NULL;
        left=mergeSort(left);
        right=mergeSort(right);
        
        node* result=merge(left,right);
        
        return result;
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
    cout<<"unsorted LinkedList :"<<endl;
    print(head1);
    cout<<endl;
    node* temp=mergeSort(head1);
    cout<<"sorted LinkedList:"<<endl;
    print(temp);

	return 0;
}