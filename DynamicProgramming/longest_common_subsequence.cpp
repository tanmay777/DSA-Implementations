#include<bits/stdc++.h>
#include<cstring>

using namespace std;

int lcs(char str1[],char str2[])
{
    int dp[100][100];
    int m=strlen(str1);
    int n=strlen(str2);

    for(int i=0;i<=m;i++)
        dp[i][0]=0;
    for(int j=0;j<=n;j++)
        dp[0][j]=0;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main(){
    char str1[100],str2[100];
    cin>>str1>>str2;
    cout<<lcs(str1,str2);
    return 0;
}
