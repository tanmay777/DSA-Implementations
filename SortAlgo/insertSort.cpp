#include<iostream>

using namespace std;

void insertionSort(int arr[],int);

int main(){
    int arr[]={INT_MIN,6,8,2,5,3,4};
    insertionSort(arr,6);
    cout<<endl;
    cout<<"Sorted array is"<<endl;
    for(int i=1;i<=6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void insertionSort(int arr[],int size){
   int i,temp,j;
   for(i=1;i<=size;i++){
       temp=arr[i];
       j=i-1;
       while(temp<arr[j]){
           arr[j+1]=arr[j];
           j--;
       }
       arr[j+1]=temp;
   cout<<"Array after "<<i<<" iteration ";
       for(int i=1;i<=6;i++){
           cout<<arr[i]<<" ";
       }
       cout<<endl;
   }

}

