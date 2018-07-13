/**
 * Author: Tanmay Jha
 * Date: 01/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

int a[100],b[100];
long long dp[100][100][100];
int M,N;

long long k_lcs(int i,int j,int k){
    long long res=0;
    if(i>=N||j>=M)
        return 0;
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    if(a[i]==b[j])
        res=1+k_lcs(i+1,j+1,k);
    else{
        if(k>0)
            res=1+k_lcs(i+1,j+1,k-1);
        res=max(res,k_lcs(i+1,j,k));
        res=max(res,k_lcs(i,j+1,k));
    }
    res=dp[i][j][k];
    cout<<dp[i][j][k]<<endl;
    return res;
}

int main()
{
    int k;
    cin>>M>>N>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<M;i++)
        cin>>a[i];
    for(int j=0;k<N;j++)
        cin>>b[j];
    long long ans=k_lcs(0,0,k);
    cout<<ans;
    return 0;
} 


