#include<iostream>

using namespace std;

int push(int [],int &, int );
int pop(int [],int &);
void display(int [],int);

const int N=5;

int main(){
    int top=-1;
    int arr[N];
    int option=1;
    int data,res;
    while(option){
        cout<<"1.Push\n";
        cout<<"2.Pop\n";
        cout<<"3.Display\n";
        cout<<"0.Exit\n";
        cin>>option;

        switch(option){
            case 1:{
                    cout<<"Enter the data: ";
                    cin>>data;
                    if(push(arr,top,data)==1)
                    {
                        cout<<"Data entered successfully\n";
                    }
                    else
                        cout<<"OVERFLOWWW!\n";
                    break;
                    }
            case 2:{
                    res=pop(arr,top);
                    if(res==-1)
                        cout<<"UNDERFLOWW!\n";
                    else{
                        cout<<res<<" is popped off";
                    break;
            }
            case 3:{
                    display(arr,top);
                    break;

            }
            case 0:{
                option=0;
            }
        }
    }
}
    return 0;
}

int push(int arr[],int &top, int data )
{
    if(top==N-1)
    {
        return -1;
}
else{
    top=top+1;
    arr[top]=data;
    return 1;
    
}
}

int pop(int arr[],int &top)
{
    if(top==-1)
        return -1;
    else
        top=top-1;
        return arr[top-1];
}

void display(int arr[],int top){
    if(top==-1)
        cout<<"Stack is empty\n";
    else{
        for(int i=top;i>=0;i--)
            cout<<arr[i]<<" ";
    }
    cout<<endl;
}
