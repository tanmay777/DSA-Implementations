/**
 * Author: Tanmay Jha
 * Date: 08/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

int total_ways(int n){
    if(n>=1&&n<=3)
        return 1;
    if(n==4)
        return 2;
    return (n<4)?n:total_ways(n-1)+total_ways(n-4);
}

int main()
{
    int n;
    cin>>n;
    cout<<total_ways(n);
    cout<<endl;
    return 0;
} 


