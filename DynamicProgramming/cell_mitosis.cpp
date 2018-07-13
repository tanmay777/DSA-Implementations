/**
 * Author: Tanmay Jha
 * Date: 01/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;


long long cell_count(const int n,int x,int y,int z){
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
            dp[i]=min(dp[i-1]+y,dp[i/2]+x);
        else
            dp[i]=min(dp[i-1]+y,dp[(i+1)/2]+x+z);
    }
    return dp[n];
}

int main()
{
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    cout<<cell_count(n,x,y,z);
    return 0;
} 


