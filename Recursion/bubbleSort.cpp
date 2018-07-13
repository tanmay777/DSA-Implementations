/**
 * Author: Tanmay Jha
 * Date: 08/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

/*void sort(int arr[],int i,int s)
{
    if(i==(s-1))
        return ;
    if(arr[1]<arr[0])
        swap(arr[1],arr[0]);
    sort(arr+1,i+1,s);
}

void bubble_sort(int arr[],int size)
{
    for(int i=0;i<size;i++)
        sort(arr,0,size-i);
}

void bubbleSort(int arr[],int n){
    if(n==0)
        return ;
    for(int j=0;j<n-1;j++)
        if(arr[j+1]<arr[j])
            swap(arr[j+1],arr[j]);
    bubbleSort(arr,n-1);
}*/

void bubbleSort2(int arr[],int n,int j){
    if(n==1)
        return ;
    if(j==n-1)
        bubbleSort2(arr,n-1,0);
    if(arr[j+1]<arr[j])
        swap(arr[j+1],arr[j]);
    bubbleSort2(arr,n,j+1);
    return;
}

int main()
{
    int arr[]={1,4,2,6,9,5,86,31};
    cout<<"Unsorted array is ";
    for(int i=0;i<8;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    bubbleSort2(arr,8,0);
        cout<<"Sorted array is ";
    for(int i=0;i<8;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
} 
