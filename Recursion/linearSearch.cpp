/**
 * Author: Tanmay Jha
 * Date: 08/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

int linearSearch(int *arr,int size,int ele){
    if(size==0)
        return 0;
    if(arr[0]==ele){
        return size;
    }
    else
        return linearSearch(arr+1,size-1,ele);
}


int main()
{
   int arr[]={1,4,2,6,9,8};
    cout<<"The array is "<<endl;
    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    int n;
    cin>>n;
    int val=linearSearch(arr,6,n);
    if(val)
        cout<<"Found at "<<7-val;
    else
        cout<<"Not Found";
    cout<<endl;
    return 0;
} 


