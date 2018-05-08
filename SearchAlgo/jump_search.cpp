#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int jump_search(const vector<int> &arr,int x)
{
    int step=sqrt(sizeof(arr));
    int prev;
    while(arr[min(step,(int)sizeof(arr))-1]<x)
    {
        prev=step;
        step+=sqrt(sizeof(arr));
        if(prev>=sizeof(arr))
            return -1;
    }

    while(prev!=min(step,(int)sizeof(arr)))
    {
        if(arr[prev]==x)
            return prev;
        prev++;
    }
    return -1;
}

int main(){
    int arr[]={1,2,34,67,89,122,156};
    int x,pos;
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));

    cout<<"The array is "<<endl;
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;

    cout<<"Enter the element you want to search: "<<endl;
    cin>>x;
    cout<<endl;

    pos=jump_search(v,x);

    if(pos==-1)
        cout<<"Element not found\n";
    else
        cout<<"Element found at position "<<pos+1;
    cout<<endl;
    return 0;
}
    
