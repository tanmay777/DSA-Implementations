/**
 * Author: Tanmay Jha
 * Date: 07/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

void order(int n,bool x){
    if(n==0)
        return ;
    if(x)
        cout<<n<<" ";
    order(n-1,x);
    if(!x)
        cout<<n<<" ";
}

int main()
{
    int n;
    cin>>n;
    order(n,true);
    cout<<endl;
    order(n,false);
    cout<<endl;
    return 0;
} 


