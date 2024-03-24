#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* bottom;

    node(int data){
        this->data=data;
        this->next=NULL;
        this->bottom=NULL;
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
            temp->bottom=left;
            temp=left;
            left=left->bottom;
        }else{
            temp->bottom=right;
            temp=right;
            right=right->bottom;
        }
    }
    
    while(left!=NULL){
        temp->bottom=left;
        temp=left;
        left=left->bottom;
    }
    
    while(right!=NULL){
        temp->bottom=right;
        temp=right;
        right=right->bottom;
    }
    ans=ans->bottom;
    return ans;
}
    
node *flatten(node *root)
{
   if(root==NULL || root->next==NULL){
       return root;
   }
   node* right=root;
   node* left=flatten(root->next);
   right->next=NULL;
   node* ans=merge(right,left);
   return ans;
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
    



	return 0;
}