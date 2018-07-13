/**
 * Author: Tanmay Jha
 * Date: 07/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

int f(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return f(n-1)+f(n-2);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
        cout<<f(i)<<" ";
    cout<<endl;
    return 0;
} 


