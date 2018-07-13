/* You are given a number, you have to reduce it to 0. You can either divide by 3. Or divide by 2. Or subtract 1. So, here we have to calculate min no. of steps to do so */

#include<bits/stdc++.h>

using namespace std;

int memo[1000];

int reduceNumber(int n){
    int q1=INT_MAX,q2=INT_MAX,q3=INT_MAX;
    if(n==1)
        return 0;
    if(memo[n]!=-1)
        return memo[n];
    if(n%3==0)
        q1=1+reduceNumber(n/3);
    if(n%2==0)
        q2=1+reduceNumber(n/2);
    q3=1+reduceNumber(n-1);
    memo[n]=min(q1,min(q2,q3));
    return memo[n];
}

int reduceNumberDP(int n){
    memo[0]=0;
    memo[1]=0;
    memo[2]=1;
    memo[3]=1;
    for(int currNum=4;currNum<=n;currNum++){
        int q1=INT_MAX,q2=INT_MAX,q3=INT_MAX;
        if(currNum%3==0)
            q1=1+memo[currNum/3];
        if(currNum%2==0)
            q2=1+memo[currNum/2];
        q3=1+memo[currNum-1];
        memo[currNum]=min(q1,min(q2,q3));
    }
    return memo[n];
}

int main(){
    int n;
    cin>>n;
    fill(memo, memo+n+1,-1);
    cout<<reduceNumberDP(n);
    return 0;
}
    
