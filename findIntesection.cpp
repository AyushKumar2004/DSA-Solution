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
    
node* findIntersection(node* head1, node* head2)
    {
        node* temp=head1;
        unordered_map<int,int> mp;
        while(temp!=NULL){
            mp[temp->data]++;
            temp=temp->next;
        }
        node* temp1=head2;
        node* prev=NULL;
        node* head=NULL;
        while(temp1!=NULL){
            if(mp.find(temp1->data)!=mp.end()){
                node* newNode=new node(temp1->data);
                mp[temp1->data]--;
                if(mp[temp1->data]==0) mp.erase(temp1->data);
                if(prev==NULL && head==NULL){
                    prev=newNode;
                    head=newNode;
                }
                else{
                    prev->next=newNode;
                    prev=newNode;
                }
            }
            temp1=temp1->next;
        }
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

    cout<<"common linkedList nodes are:"<<endl;

    node* temp=findIntersection(head1,head2);

    print(temp);
    

	return 0;
}