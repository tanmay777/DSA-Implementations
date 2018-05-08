#include<iostream>

using namespace std;

void mergeSort(int arr[],int,int);
void merge(int arr[],int,int,int);

int main(){
    int arr[]={9,8,7,6,5,4};
    cout<<"Inserted array is ";
    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    mergeSort(arr,0,5);
    cout<<"Sorted array is ";
    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

void mergeSort(int arr[],int beg,int end){
    int mid;
    if(beg<end){
        mid=(beg+end)/2;
        mergeSort(arr,beg,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}

void merge(int arr[],int beg,int mid,int end){
    int index=beg;
    int i=beg;
    int j=mid+1;
    int temp[10];
    while((i<=mid)&&(j<=end)){
        if(arr[i]<arr[j])
        {
            temp[index]=arr[i];
            i++;index++;
        }
        else if(arr[i]>arr[j])
        {
            temp[index]=arr[j];
            j++;index++;
        }
        else
        {
            temp[index]=arr[i];
            i++;j++;index++;
        }
    }

    if(i<=mid){
        while(i<=mid)
        {
            temp[index]=arr[i];
            i++; index++;
        }
    }
    else{//This was intended if both the number in comparison had same value. But I don't why but its not working with this.
        while(j<=end){
            temp[index]=arr[j];
            j++;index++;
        }
    }
    for(i=beg;i<index;i++)
        arr[i]=temp[i];
}
