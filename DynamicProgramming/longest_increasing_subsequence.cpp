/*
    In longest Increasing subsequence, we have to find length of long increasing subsequence in an array of number.
    For eg in 3 10 2 1 20 Then longest increasing subsequence will be 3 10 20. Here, length will be 3.
    in 3 2, it will be 3 or 2. So, length will be 1.

    Explanation in coding copy 3.

*/
#include<bits/stdc++.h>
 
using namespace std;

int lis_dp(int arr[],int const size){
    int val[size];
    cout<<"size is "<<size<<endl;
    for(int i=0;i<size;i++)
        val[i]=1;
    int best=-1;
    for(int i=1;i<size;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
                val[i]=max(val[i],val[j]+1);
        }
        best=max(val[i],best);
    }
    return best;
}

int main(){
    int arr[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int ans=lis_dp(arr,n);
    cout<<ans<<endl;
    return 0;
}
