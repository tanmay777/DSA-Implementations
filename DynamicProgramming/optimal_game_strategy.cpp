/**
 * Author: Tanmay Jha
 * Date: 01/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

int optimal_score(vector<int> &v,int i,int j){
    if(i>j)
        return 0;
    return  max(
                    v[i]+
                    min(    
                        optimal_score(v,i+2,j)
                        ,optimal_score(v,i+1,j-1)),
                    v[j]+
                    min(
                        optimal_score(v,i,j-1)
                        ,optimal_score(v,i+1,j-1))
                );
}

int main()
{
    int arr[]={7,3,1,6,2,8,10,11};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    cout<<optimal_score(v,0,sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
} 


