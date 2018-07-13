#include<iostream>

using namespace std;

int insert(int arr[],int);
int del(int arr[]);
void display(int arr[]);

const int size=5;

int front=-1,rear=-1;

int main(){
    int arr[size],data;
    char ch;
    do{
        cout<<"\nEnter your option\n1.Insert\n2.Delete\n3.Display\n0.Exit\n";
        cin>>ch;
        switch(ch){
            case '1':
                cout<<"Enter the data which you want to insert: \n";
                cin>>data;
                if(insert(arr,data))
                    cout<<"Data Inserted\n";
                else
                    cout<<"OVERFLOWW\n";
                break;
            case '2':
                if(del(arr))
                    cout<<"Data Deleted";
                else
                    cout<<"UNDERFLOWWW!";
                break;
            case '3':
                display(arr);
                break;
            case '0':
                ch='0';
                break;
        }
    }while(ch!='0');

    return 0;
}

int insert(int arr[],int data){
    if(front==-1)
        front=rear=0;
    else if(rear==size-1)
        return 0;
    else
        rear++;
    arr[rear]=data;
    return 1;
}

int del(int arr[]){
    if(front==-1)
        return 0;
    else if(front==rear)
        front=rear=-1;
    else
        front++;
    return 1;
}

void display(int arr[]){
if(front==-1)
    cout<<"EMPTYYY";
else{
    for(int i=front;i<=rear;i++)
        cout<<arr[front]<<"<-";
    cout<<endl;
    }
}
