#include<iostream>

using namespace std;

void quickSort(int arr[],int,int);
int partition(int arr[],int,int);

int main(){
    int i;
    int arr[]={2,5,1,6,8,3};
    cout<<"Input array is ";
    for(i=0;i<6;i++)
        cout<<arr[i]<<" ";
    quickSort(arr,0,5);
    cout<<"\nSorted array is ";
    for(i=0;i<6;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

void quickSort(int arr[],int p,int r){
    if(p<r){
        int q=partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,p+1,r);//We are not taking qth element as it is already sorted after calling partition function
    }
}

int partition(int arr[],int p,int r){
    int i=p-1;
    int j=p;
    int temp;
    while(j<=r-1){
        if(arr[j]<arr[r]){
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        j++;
    }
    temp=arr[r];
    arr[r]=arr[i+1];
    arr[i+1]=temp;
    return i+1;
}
