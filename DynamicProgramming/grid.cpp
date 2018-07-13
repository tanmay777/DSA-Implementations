/**
 * Author: Tanmay Jha
 * Date: 03/07/2018
 * Email: tanmay.jha1@gmail.com
 */

/*  In Grid Problem:
    See, we have to find the shortest distance to our destination box in the below diagram.
    Let the destination box be (2,2)(0-indexed). Value inside the box are the weight through that direction. 
    |1|2|3
    |4|8|2
    |1|5|3
*/

#include<bits/stdc++.h>

using namespace std;

int dp[100][100];

int minPathDp(int grid[][3],int const s){
    int arr[s][s];
    arr[0][0]=grid[0][0];
    for(int i=1;i<s;i++){
        arr[i][0]=arr[i-1][0]+grid[i][0];
        arr[0][i]=arr[0][i-1]+grid[0][i];
    }
    
    for(int i=1;i<s;i++){
        for(int j=1;j<s;j++)
        {
            arr[i][j]=grid[i][j]+(arr[i-1][j]>arr[i][j-1]?arr[i][j-1]:arr[i-1][j]);
        }
    }
    
    return arr[s-1][s-1];
}

int minPath(int grid[][3],int i,int j,int s){
    if(dp[i][j]!=-1)
        return dp[i][j];

    int v1=INT_MAX,v2=INT_MAX;
    if(i==s-1&&j==s-1)
        return grid[i][j];
   
    if(i+1<s)
        v1=grid[i][j]+minPath(grid,i+1,j,s);
    if(j+1<s)
        v2=grid[i][j]+minPath(grid,i,j+1,s);
    dp[i][j]=min(v1,v2);    
    return dp[i][j];
}

int main() 
{
    memset(dp,-1,sizeof(dp));
    int grid[][3]={{1,2,3},{4,8,2},{1,5,3}};
    //cout<<minPath(grid,0,0,3);
    cout<<minPathDp(grid,3);
    cout<<endl;
    return 0;
} 

