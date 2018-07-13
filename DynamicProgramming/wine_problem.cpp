/* Ques: Wine Problem:	
Let these be the four wine bottle
		1 4 2 3
		| | | |

Here, we have to sell wines. We can only sell one wine every year. And we can sell only from one side. The selling price of wine is the (yearNumber)*(ValueOfWine(Written on Top)) So, now we have to maximise this profit. 

*/ 

#include<bits/stdc++.h>

using namespace std;

int cnt=0;
int memo[1000][1000];
int dp[1000][1000];

int max_profit(int arr[],int beg,int end,int year){
    if(beg>end)
        return 0;
    if(memo[beg][end]!=-1)
        return memo[beg][end];
    cnt++;
    int q1=arr[beg]*year+max_profit(arr,beg+1,end,year+1);
    int q2=arr[end]*year+max_profit(arr,beg,end-1,year+1);

    memo[beg][end]=max(q1,q2);

    return max(q1,q2);
}

void max_profit_DP(int arr[],int n)
{
    int year=n;
    for(int i=0;i<n;i++)
        dp[i][i]=arr[i]*year;

    year--;
    int start,end;
    for(int len=2;len<=n;len++){
        start=0;
        end=n-len;
        while(start<=end)
        {	
	    end=start+len-1;
            dp[start][end]=max(
                arr[start]*year+dp[start+1][end],
                arr[end]*year+dp[start][end-1]);
            start++;
        }
        year--;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Maximum profit was "<<dp[0][n-1]<<endl;

}

int main(){
    int n;
    int arr[100];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    memset(memo,-1,sizeof(memo));
 //   cout<<"Maximum profit is "<<max_profit(arr,0,n-1,1)<<endl;
  // cout<<"Total number of calls are:"<<cnt<<endl;a
    max_profit_DP(arr,n);
    return 0;
}
