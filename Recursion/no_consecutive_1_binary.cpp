/**
 * Author: Tanmay Jha
 * Date: 06/07/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

int count_seq(int *in,int i,int prev,int n){
    int v1=0,v2=0;
    if(i==n)
       return 1; 
    in[i]=0;
    v1=count_seq(in,i+1,0,n);
    if(prev!=1){
        in[i]=1;
        v2=count_seq(in,i+1,1,n);
    }
    return v1+v2;
}

int main()
{
    int n;
    cin>>n;
    int in[100];
    int out[100];
    cout<<count_seq(in,0,0,n);
    cout<<endl;
    return 0;
} 


