/* Min Edit Distance is the min. distance between the source string and the destination string. 
See, you are allowed to do three operations. 1) Insertion 2) Deletion 3) Replacement to the source string to obtain the final string. Cost of all operations is 1. 
For eg. Cats to cast will be 2. As s will be inserted after a and deleted after t. 

So, basically in this question. We will be given an i/p string and we have to tell the minimum number of operations to obtain the destination strings. 

Recursive Approach
See, suppose we have to convert sunday to saturday. 
What we can do is. we will have i and j pointer. Both at the starting to sunday and saturday respective. If value of i and j are same, then we won't do anything and we will move forward. As, in case now. So, i will be at u and j will be at a. 

Now, we will get results from three ways. 
1. we can replace u with a. So, function call will be (int,i+1,out,j+1)+1
2. We can delete u. So , function call will be (int,i+1,out,j)+1
3. Last we can insert a before u, function call will be (int,i,out,j+1)+1

We will take that one from which we will get the minimum value. 

See, copy to understand top down approach
*/


#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
/*
int min_edit_dist_td(char *inp,char *out,int i,int j){
    if((i==strlen(inp))||(j==strlen(out)))//Base case is wrong
        return 0;
    int rep=0;
    int del=0;
    int ins=0;
    if(inp[i]==out[j])
         min_edit_dist_td(inp,out,i+i,j+1);
    else{
        int rep=min_edit_dist_td(inp,out,i+1,j+1)+1;
        int del=min_edit_dist_td(inp,out,i+1,j)+1;
        int ins=min_edit_dist_td(inp,out,i,j+1)+1;
    }
    return min(min(rep,del),ins);
    
}
*/
int min_edit_dist(char inp[],char out[]){
    int dp[100][100]={};
    dp[0][0]=0;
    int i,j,q1,q2,q3;
    int m=strlen(inp);
    int n=strlen(out);
    for(i=1;i<=n;i++) dp[0][i]=1+dp[0][i-1];
    for(j=1;i<=m;j++) dp[j][0]=1+dp[j-1][0];
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            q1=dp[i-1][j-1];
            q2=dp[i-1][j];
            q3=dp[i][j-1];
            dp[i][j]=min(q1,min(q2,q3))+(inp[i-1]!=out[j-1]);
        }
    }
    return dp[m][n];
}
int main(){
    char inp[100],out[100];
    cin>>inp>>out;
    cout<<min_edit_dist(inp,out);
    //cout<<min_edit_dist_td(inp,out,0,0);
    return 0;
}
