#include<iostream>

using namespace std;

int getMax(int arr[],int size){
    int large=arr[0];
    for(int i=0;i<size;i++)
        if(arr[i]>large)
            large=arr[i];
    return large;
}

void countSort(int arr[],int size,int exp){
    int count[10]={0};
    int output[size];
    int i;
    for(i=0;i<size;i++)
        count[(arr[i]/exp)%10]++;

    for(i=1;i<10;i++)
        count[i]+=count[i-1];

    for(i=size-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i=0;i<size;i++)
        arr[i]=output[i];
}

void radixSort(int arr[],int size){
    int max=getMax(arr,size);
    for(int exp=1;max/exp>0;exp*=10){
        countSort(arr,size,exp);
    }
}

int main(){
    int arr[]={1,56,123,2,65,32};

    cout<<"Our input array is ";
    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    radixSort(arr,sizeof(arr)/sizeof(arr[0]));
    cout<<"Sorted array is ";
    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
