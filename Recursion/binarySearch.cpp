/**
 * Author: Tanmay Jha
 * Date: 08/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

int binary_search(int *arr,int low,int high,int key){
    if(low>high)
        return -1;
    int m=(low+high)/2;
    if(arr[m]==key)
        return m;
    else if(arr[m]>key)
        return binary_search(arr,low,m-1,key);
    else
        return binary_search(arr,m+1,high,key);
}

int main()
{
    int arr[]={1,2,6,9,34,56};
    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    int n;
    cin>>n;
    cout<<binary_search(arr,0,6,n);
    cout<<endl;
    return 0;
} 


