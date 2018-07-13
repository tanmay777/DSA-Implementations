#include<bits/stdc++.h>

using namespace std;

int memo[100][100];

//Bottom Up Approach
int max_profit_bu(int wts[],int prices[],int N,int W){
    int dp[100][100]={0};
    int inc,exc;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=W;j++){
            inc=0;exc=0;
            if(wts[i-1]<=j){
                inc=prices[i-1]+dp[i-1][j-wts[i-1]];
                //For unbounded knapsack change above dp[i-1] to dp[i]
            }
            exc=dp[i-1][j];
            dp[i][j]=max(inc,exc);
        }
        for(int i=0;i<=N;i++){
            for(int j=0;j<=W;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return dp[N][W];
}


//Top Down Approach
int max_profit(int wts[],int prices[],int N,int W){
    
    if(memo[N][W]!=-1)
        return memo[N][W];
    if(N==0||W==0)
        return 0;
    int inc=0,exc=0;
    if(W-wts[N-1]>=0)
        inc=prices[N-1]+max_profit(wts,prices,N-1,W-wts[N-1]);
        //For unbounded knapsack, change third parameter of max_profit to N from N-1

    exc=max_profit(wts,prices,N-1,W);
    memo[N][W]=max(inc,exc);

    return memo[N][W];
}

int main(){
    int wts[]={2,2,3,1};
    int prices[]={5,20,20,10};
    int N=4;
    int W=5;
    memset(memo,-1,sizeof(memo));
    cout<<max_profit(wts,prices,N,W)<<endl;
    cout<<max_profit_bu(wts,prices,N,W)<<endl;
    return 0;
}
