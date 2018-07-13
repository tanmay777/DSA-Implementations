/**
 * Author: Tanmay Jha
 * Date: 02/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

int a[10],dp[100][100];

long long sum(int s,int e){
    long long ans=0;
    for(int i=s;i<=e;i++){
        ans+=a[i];
        ans%=100;
    }
    return ans;
}
long long mixture(int i,int j){
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]=INT_MAX;
    for(k=i;k<=j;k++)
        dp[i][j]=min(dp[i][j],mixture(i,k)+mixture(k+1,j)+sum(i,k)*sum(k+1,j));
    return dp[i][j];

}

int main()
{
    memset(dp,-1,sizeof(dp));
    
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<mixture(0,n-1);
    return 0;
} 


