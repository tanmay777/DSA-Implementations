#include<iostream>
#include <unistd.h>

using namespace std;

struct Node{
    int info;
    Node *next;
}*start,*ptr,*save,*newptr,*rear;

Node* createNewNode(int);
void insertBeg(Node *);
void display(Node *);
void insertEnd(Node *);
void del();
Node* InsertNth(Node *head, int data, int position);

int main(){
    start=rear=NULL;
    int inf,n;
    char ch='y';
    while(ch=='y'||ch=='Y'){
        cout<<"Enter the information of the new node ";
        cin>>inf;
        newptr=createNewNode(inf);
        if(newptr!=NULL){
        }
        else{
            cout<<"Cannot create new node Aborting";
            exit(1);
        }
        insertBeg(newptr);
        //insertEnd(newptr);
        /*cout<<"Enter where you want to enter the node ";
        cin>>n;
        start=InsertNth(start,inf,n);

        */cout<<"\nOn inserting the list is:"<<endl;
        display(start);
        cout<<"Press Y to insert more node else N to exit";
        cin>>ch;
    }

    /*ch='y';

    while(ch=='y'||ch=='Y'){
        del();
        cout<<"On deleting the list is:"<<endl;
        display(start);
        cout<<"Press Y to delete more node else N to exit";
        cin>>ch;
        }
*/
    return 0;
}

Node* InsertNth(Node *head, int data, int position)
{
    Node *tmp;
    Node *np=new Node;
    np->next=NULL;
    np->info=data;
    
    Node *save=head;
    if(head==NULL){
        head=np;
        cout<<"\n Condition (head==NULL)";
    }
    
    else if(position<=0){
        tmp=head;
        head=np;
        np->next=tmp;
        cout<<"\n Condition (position==0)";
    }
    
    else{
        for(int i=0;i<position-1;i++){
            if(save->next!=NULL)
                save=save->next;
        }
        if(position==1)
            save=head;
    
        tmp=save->next;
        save->next=np;
        np->next=tmp;
    }
    return head;
}


void del(){
    if(start==NULL){
        cout<<"Underflow";
    }
    else{
        save=start;
        start=start->next;
        delete save;
}}

Node* createNewNode(int x){
    ptr=new Node;
    ptr->info=x;
    ptr->next=NULL;
    return ptr;
}

void insertBeg(Node *ptr){
    if(start==NULL){
        start=ptr;
    }
    else{
        /*save=start;
        start=ptr;
        ptr->next=save;
        */
        ptr->next=start;
        start=ptr;
    }
}

void display(Node *ptr){
    while(ptr!=NULL){
        cout<<ptr->info<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

void insertEnd(Node *np){
    if(start==NULL){
        start=rear=np;
    }
    else{
        rear->next=np;
        rear=np;
        }   
}

Node* Delete(Node *head, int position)
{
    Node *save=head;
    if(head==NULL)
        return head;
    else if(position==0)
    {
        head=head->next;
        delete save;
    }
    else if(position==1){
        save=head->next;
        head->next=save->next;
        delete save;
    }
    else{
        for(int i=0;i<position-1;i++){
            save=save->next;
        }
        Node *tmp=save->next;
        save->next=tmp->next;
        delete tmp;
    }
    return head;
    
    
}


