// Replace all occurrences of pi with 3.14
/**
 * Author: Tanmay Jha
 * Date: 12/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

void replace_pi(string x,int i,int m){
    if(i==m)
        return ;
    if(x[0]=='p'&&x[0]=='i'){
        x.replace(0,2,"3.14");
        replace_pi(x.substr(2,m-i-2),i+2,m);
    }
    else
        replace_pi(x.substr(1,m-i-1),i+1,m);
}
int main()
{
    int n;
    string x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        replace_pi(x,0,x.length());
        cout<<x;
    }
    cout<<endl;
    return 0;
} 


