/*
Ques: Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change?
*/
#include<bits/stdc++.h>

using namespace std;

int memo[10000];

int minCoins(int us_coins[],int n,int amt){
    if(memo[amt]!=-1)
        return memo[amt];
    int res=0,best=INT_MAX;
    if(amt==0)
        return 0;
    for(int i=0;i<n;i++)
    {
        if((amt-us_coins[i])>=0)
        {   
            res=minCoins(us_coins,n,amt-us_coins[i]);
            best=min(res,best);
        }
    }
    memo[amt]=best+1;
    return best+1;
}

int coinNeeded(int coins[],int n,int amt){
    int dp[100]={0};
    dp[0]=0;
    dp[1]=1;
    dp[7]=1;
    dp[10]=1;
    for(int i=2;i<=amt;i++){
        if(i==7||i==10)
            continue;
        dp[i]=1+min(dp[i-1],min(i-7>0?dp[i-7]:INT_MAX,i-10>0?dp[i-10]:INT_MAX));
        for(int j=0;j<=amt;j++)
            cout<<dp[j]<<" ";
        cout<<endl;
    }   
    return dp[amt];
}


int main(){
    int us_coins[]={1,7,10};
    int n=3;
    int amount=15;
    fill(memo,memo+amount+1,-1);
    cout<<minCoins(us_coins,n,amount)<<endl;

    fill(memo,memo+amount+1,-1);
    int india_coins[]={1,2,5,10,50};
    n=5;
    int paise=13;
    cout<<minCoins(india_coins,n,paise)<<endl;

    cout<<coinNeeded(us_coins,n,amount)<<endl;
    return 0;
}
