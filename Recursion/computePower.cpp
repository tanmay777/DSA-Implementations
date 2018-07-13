/**
 * Author: Tanmay Jha
 * Date: 07/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

int compute_power(int x,int p){
    if(p==0)
        return 1;
    else
        return x*compute_power(x,p-1);
}

int efficient_power(int x,int p){
    if(p==0)
        return 1;
    else if(p%2!=0)
        return x*(pow(efficient_power(x,p/2),2));
    else
        return (pow(efficient_power(x,p/2),2));
}
        
int main()
{
    int x,p;
    cin>>x>>p;
    cout<<efficient_power(x,p);
    cout<<endl;
    return 0;
} 


