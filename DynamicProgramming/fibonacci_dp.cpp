#include<iostream>
#include<string>

using namespace std;

long memo[1000];

long fib(long n){
   /* if(n==0) return 0;
    if(n==1) return 1;
    if(memo[n]!=-1)
    {
        return memo[n];
    }
    long ans= (fib(n-1)+fib(n-2));
    memo[n]=ans;
    return ans;*/
    int dp[1000]={0};
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}

int main(void){
    int n;
    cin>>n;
    for(int i=0;i<=1000;i++)
        memo[i]=-1;
    cout<<fib(n)<<endl;

    return 0;
}


