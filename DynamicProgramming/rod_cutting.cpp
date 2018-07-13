/* 
Ques: See, you have been given a rod of length n. 
And then you have been given cost of selling each length. 
We have to tell the maximum profit we can make by selling the whole rod.
Now, you can either sell the rod as it is, or you can cut into n length
pieces and then gain the total profit by adding
profit of each rod of length.Or some other combination. 

For eg. Let length be 4.
Then cost of selling length 1 : Rs 2
                            2 : Rs 3
                            3 : Rs 2
                            4 : Rs 5
*/

#include<bits/stdc++.h>

using namespace std;

int memo[1000];
int dp[1000];

int max_profit(int arr[],int size){
    if(size==0)
        return 0;
    if(memo[size]!=-1)
        return memo[size];
    int best=0;
    for(int len=1;len<=size;len++){
        int currProfit=arr[len]+max_profit(arr,size-len);
        best=max(currProfit,best);
    }
    memo[size]=best;
    return best;
}

int max_profit_dp(int arr[],int size){
    int best;
    for(int len=1;len<=size;len++){
        best=0;
        for(int curr=1;curr<=len;curr++)
        {
            best=max(best,arr[curr]+dp[len-curr]);
        }
        dp[len]=best;
    }
    return dp[size];

}

int max_profit_dp_method_2(int arr[],int const size){
    int v[size+1];
    v[1]=arr[1];
    for(int i=2;i<=size;i++)
    {
        if(v[i-1]+arr[1]>arr[i])
            v[i]=v[i-1]+arr[1];
        else
            v[i]=arr[i];
    }
    return v[size];
}

int main(){
    int n;
    cin>>n;
    fill(memo,memo+n+1,-1);
    fill(dp,dp+n+1,0);
    int arr[100];
    for(int i=1;i<n;i++)
        cin>>arr[i];
  // cout<<"Max profit is "<<max_profit(arr,n)<<endl;
    cout<<"Max profit is "<<max_profit_dp(arr,n)<<endl;
    cout<<"Max profit is "<<max_profit_dp_method_2(arr,n)<<endl;
    return 0;
}
