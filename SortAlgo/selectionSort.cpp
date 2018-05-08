#include<iostream>

using namespace std;

void selectionSort(int arr[],int);

int main(){
    int arr[]={6,8,2,5,3,4};
    selectionSort(arr,8);
    cout<<endl;
    cout<<"Sorted array is"<<endl;
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void selectionSort(int arr[],int size){
    int pos=0,i,j,temp=0,small=0;
    for(int i=0;i<6;i++)
    {
        small=arr[i];
        pos=i;
        
        for(int j=i+1;j<6;j++){
            if(arr[j]<small)
            {
                small=arr[j];
                pos=j;
            }
        }
        
        temp=arr[pos];
        arr[pos]=arr[i];
        arr[i]=temp;

        cout<<"array status after "<<i<<" iteration";
        for(int i=0;i<6;i++){
           cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

