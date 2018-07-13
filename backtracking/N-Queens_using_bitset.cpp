/**
 * Author: Tanmay Jha
 * Date: 12/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

bitset<30> col,d1,d2;

void solveNQueens(int r,int n,int &ans){
    if(r==n)
    {
        ans++;
        return;
    }
    for(int c=0;c<n;c++){
        if(!col[c]&&!d1[r-c+n-1]&&!d2[r+c])
        {
            col[c]=d1[r-c+n-1]=d2[r+c]=1;
            solveNQueens(r+1,n,ans);
            col[c]=d1[r-c+n-1]=d2[r+c]=0;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int ans=0;
    solveNQueens(0,n,ans);
    cout<<ans;
    cout<<endl;
    return 0;
} 


