#include<iostream>
#include<vector>
using namespace std;

int binarySearch(const vector<int> &v,int x){
    int low=0;
    int high=v.size();
    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]==x)
            return mid;
        else if(v[mid]<x)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
int main()
{
    int x,pos;
    int arr[]={1,4,5,8,12,16,25,27,52};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));

    cout<<"Vector is ";
    for(vector<int>::iterator i=v.begin();i!=v.end();i++)
        cout<<*i<<" ";
    cout<<endl;

    cout<<"Enter the element which you want to search: ";
    cin>>x;

    pos=binarySearch(v,x);
    if(pos!=-1)
        cout<<"Element is at position "<<pos+1<<endl;
    else
        cout<<"Element not found \n";
    return 0;
}
