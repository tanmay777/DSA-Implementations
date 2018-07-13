/**
 * Author: Tanmay Jha
 * Date: 26/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

void rotateArray(int arr[],int size,int d){
    int n=gcd(size,d);
    int temp,k;
    for(int i=0;i<n;i++)
        {
            temp=arr[i];
            k=(i+d)%size;
            arr[i]=arr[k];
            while(1){
                if(((k+d)%size)==i){
                    arr[k]=temp;
                    break;
                }
                arr[k]=arr[(k+d)%size];
                k=(k+d)%size;
                }
            arr[k]=temp;
        }
}

int main()
{
    int arr[]={2,4,5,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int d;
    cin>>d;   
    rotateArray(arr,n,d);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
} 


