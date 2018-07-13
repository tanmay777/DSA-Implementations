/* Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. */

/**
 * Author: Tanmay Jha
 * Date: 25/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

unordered_map<string,bool> lookup;

bool subset_bottom_up(int arr[],int n,int sum){
    bool T[n+1][sum+1];
    for(int i=0;i<=n;i++)
        T[i][0]=true;
    for(int j=1;j<=sum;j++)
        T[0][j]=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]>j)
                T[i][j]=T[i-1][j];
            else
                T[i][j]=T[i-1][j]||T[i-1][j-arr[i-1]];
        }
    }
    return T[n][sum];
}

bool subset_top_down(int arr[],int n,int sum){
    if(sum==0)
        return true;
    if(n<0||sum<0)
        return false;
    string key=to_string(n)+"|"+to_string(sum);
    if(lookup.find(key)==lookup.end()){
        bool include=subset_top_down(arr+1,n-1,sum-arr[0]);
        bool exclude=subset_top_down(arr+1,n-1,sum);
        lookup.insert(pair<string,bool>(key,include||exclude));
    }
    return lookup[key];
}

//I have ran the below program to check if it actually works. 
void subset_sum(int arr[],int sum,int i,int n){
	if(sum==0)
		cout<<"True";
	else{
		if(sum-arr[0]>=0&&i+1<=n){
			subset_sum(arr,sum-arr[i],i+1);
			subset_sum(arr,sum,i+1);
		}
	}
}

int main()
{
    int n;
    int arr[]={5,3,2,6};
    n=sizeof(arr)/sizeof(arr[0]);
    int sum;
    cin>>sum;
    if(subset_top_down(arr,n,sum))
        cout<<"Present";
    else
        cout<<"Not Present";
    cout<<endl;
    if(subset_bottom_up(arr,n,sum))
        cout<<"Present";
    else
        cout<<"Not Present";
    cout<<endl;

    return 0;
} 


