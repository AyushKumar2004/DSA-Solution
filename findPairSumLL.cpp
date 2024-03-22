#include<iostream>
#include<vector>
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

vector<pair<int, int>> findPairsWithGivenSum(node *head, int target)
    {
        node* first=head;
        node* last=head;
        vector<pair<int,int>> ans;
        while(last->next!=NULL){
            last=last->next;
        }
        while(first!=last && last->next!=first){
            if(last->data+first->data==target){
                ans.push_back({first->data,last->data});
                first=first->next;
                last=last->prev;
            }
            else{
                if(first->data+last->data<target){
                    first=first->next;
                }else{
                    last=last->prev;
                }
            }
        }
        return ans;
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

    vector<pair<int,int>> ans=findPairsWithGivenSum(head,9);

    for(auto it: ans){
        cout<<"{"<<it.first<<","<<it.second<<"}"<<endl;
    }

    return 0;
}