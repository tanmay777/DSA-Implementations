/* 
A robot is designed to move on a rectangular grid of M rows and N columns. The robot is initially positioned at (1, 1), i.e., the top-left cell. The robot has to reach the (M, N) grid cell. In a single step, robot can move only to the cells to its immediate east and south directions. That means if the robot is currently at (i, j), it can move to either (i + 1, j) or (i, j + 1) cell, provided the robot does not leave the grid.

Now somebody has placed several obstacles in random positions on the grid, through which the robot cannot pass. Given the positions of the blocked cells, your task is to count the number of paths that the robot can take to move from (1, 1) to (M, N).

Since the answer can get very large, output the answer modulo 1000000007.

*/

/**
 * Author: Tanmay Jha
 * Date: 31/05/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int dp[1001][1001];
/*
In this solution we are creating a 2D dp. In which we are calculating for every (i,j) position, the number ways to reach
it. For eg. There will be only 1 way to reach every element in first row. And first column. Provided we don't have any
obstacle. If we have an obstacle the number of ways to reach next to the obstacle will be zero in both row and col case.
As we can only move right and down. 
*/

int NumWays(int M,int N){
    if(dp[0][0]==-1||dp[M-1][N-1]==-1)
        return 0;
    for(int i=0;i<N;i++){
        if(dp[0][i]==-1)
            break;
        dp[0][i]=1;
    }
    for(int i=0;i<M;i++){
        if(dp[i][0]==-1)
            break;
        dp[i][0]=1;
    }
    for(int i=1;i<M;i++)
    {
        for(int j=1;j<N;j++){
            if(dp[i][j]==-1)
                continue;
            if(dp[i-1][j]!=-1)
                dp[i][j]=dp[i-1][j]%MOD;
            if(dp[i][j-1]!=-1)
                dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
        }
    }
   return dp[M-1][N-1];
}


int main()
{
    memset(dp,0,sizeof(dp));
    int M,N,P;
    cin>>M>>N>>P;

    for(int i=0;i<P;i++){
        int X,Y;
        cin>>X>>Y;
        dp[X-1][Y-1]=-1;
    }

    cout<<NumWays(M,N)<<endl;
    return 0;
} 


