/*
See, here we have stairs. Like this
       _
      _ 
     _
    _

Now, we have to reach the top of the ladder. We can either take 1 step,2 step or 3 step at a time. We have to find the
total number of ways to reach the top of the stairs.
eg if total steps are 4. Few of the way can be 1,1,1,1 or 1,2,1 or 2,2 or 3,1 or 1,3 etc.

*/
#include<bits/stdc++.h>

using namespace std;

int memo[100];
int dp[100];

int no_of_steps(int n){
 
    if(n==0)
        return 1;
    if(n<0)   
        return 0;
   
    if(memo[n]!=-1)
        return memo[n];
   
    int q1=0;
    int q2=0;
    int q3=0;
    q1=no_of_steps(n-1);
    q2=no_of_steps(n-2);
    q3=no_of_steps(n-3);
  
    memo[n]=q1+q2+q3;
    
    return (memo[n]);
}

int ways(int n,int j){
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    int ans=0;
    for(int i=1;i<=j;i++)
        ans+=ways(n-i,j);
    return ans;
}

void ways_BU(int n,int k){
    int dp[100];
    fill(dp,dp+n+1,-1);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=2;i<=n;i++)
    {   
        dp[i+1]=2*dp[i]-dp[i-k];//This is done through a trick. I don't think so its that necessary to learn it. 
    }
    /* See above problem also could be solved as:
    dp[0]=1;
    for(int step=1;step<=n;step++)
    {
        for(int j=1;j<=k;j++){
            if(step-j>=0)
                dp[step]+=dp[step-j];
    }
    */
    cout<<dp[n];
}

int main(){
    int n;
  //cin>>n;
  //fill(memo,memo+n+1,-1);
  //cout<<no_of_steps(n)<<endl;
 // cout<<ways(4,3); 4 is stair length and 3 is the possible step size, i.e 1,2,3.e
ways_BU(4,3);
    return 0;
}
