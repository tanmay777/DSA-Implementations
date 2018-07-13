/*
There will be a set of numbers. There will be two players. 
player 1 will pick a number, x.
Score of player 1 will be x*(count of x).
player 2 will remove x-1 and x+1 from the set. 
player 1 will again pick a number. And new score will be added to prev one.
player 2 will again remove x-1 and x+1 and so on. Till no numbers are left.
What is the maximum score player 1  can

/**
 * Author: Tanmay Jha
 * Date: 01/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

int count(int arr[],int ele,int s){
    int count=0;
    for(int i=0;i<s;i++)
        if(arr[i]==ele)
            count++;
    return count;
}

int max_score(int arr[],const int s){
    int dp[s];
    dp[0]=0;
    dp[1]=1*count(arr,1,s);
    int max_count=0;
    for(int i=2;i<s;i++)
        dp[i]=max(dp[i-1],(dp[i-2]+i*count(arr,i,s)));
    for(int i=0;i<s;i++)
    {
        if(max_count<dp[i])
            max_count=dp[i];
    }
   return max_count;
}

int main()
{
    int arr[]={1,2,4,2,3};
    cout<<max_score(arr,5)<<endl;
    return 0;
} 


