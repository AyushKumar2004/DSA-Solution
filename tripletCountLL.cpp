#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    ~node(){
        int val=this->data;
        if(this->next!=NULL || this->prev!=NULL){
            delete next;
            delete prev;
            this->next=NULL;
            this->prev=NULL;
        }
        cout<<"Meemory is free for the data with node:"<<val<<endl;
    }
};

void insertAtHead(node* &head,node* &tail,int data){
    if(head==NULL){
        node* newNode=new node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    node* newNode=new node(data);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}

void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int countTriplets(node* head,int target){
    node* ptr1,*ptr2,*ptr3;
    int count=0;
    unordered_map<int,node*> mp;
    for(ptr1=head;ptr1!=NULL;ptr1=ptr1->next){
        mp[ptr1->data]=ptr1;
    }

    for(ptr2=head;ptr2!=NULL;ptr2=ptr2->next){
        for(ptr3=ptr2->next;ptr3!=NULL;ptr3=ptr3->next){
            int sum=ptr2->data+ptr3->data;
            if(mp.find(target-sum)!=mp.end() && mp[target-sum]!=ptr2 && mp[target-sum]!=ptr3){
                count++;
            }
        }
    }

    return (count/3);
}

int main(){

    node* head=NULL;
    node* tail=NULL;

    insertAtHead(head,tail,8);
    insertAtHead(head,tail,7);
    insertAtHead(head,tail,6);
    insertAtHead(head,tail,5);
    insertAtHead(head,tail,4);
    cout<<"doubly Linkedlist:"<<endl;
    print(head);
    cout<<"number of the triplelet count:";
    cout<<countTriplets(head,15);

    return 0;
}