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

bool detectLoop(node* head)
    {   
        node* temp=head;
        unordered_map<node*,int> mp;
        while(temp!=NULL){
            if(mp[temp]==1){
                return true;
            }
            mp[temp]=1;
            temp=temp->next;
        }
        return false;
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

    if(detectLoop(head)){
        cout<<"yes,Loop is present"<<endl;
    }else{
        cout<<"No,Loop is not present"<<endl;
    }

	return 0;
}