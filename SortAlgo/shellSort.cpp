#include<iostream>

using namespace std;

void shellSort(int arr[],int n){
    int flag=1,i,temp;
    int gapsize=n;
    while(gapsize>1||flag==1)
    {
        flag=0;
        gapsize=(gapsize+1)/2;
        for(i=0;i<(n-gapsize);i++){
            if(arr[i]>arr[gapsize+i]){
                temp=arr[i];
                arr[i]=arr[gapsize+i];
                arr[gapsize+i]=temp;
                flag=0;
            }
        }
    }
}

int main(){
    int arr[]={1,5,2,67,8,43,21};
    cout<<"Input array is ";
    for(int i=0;i<7;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    shellSort(arr,7);
    cout<<"Output array is ";
    for(int i=0;i<7;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
