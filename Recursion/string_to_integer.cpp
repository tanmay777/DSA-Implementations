/**
 * Author: Tanmay Jha
 * Date: 07/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

void char_to_integer(char *a,int s){
    if(s==0)
        return ;
    cout<<a[0]-'0'<<" ";
    char_to_integer(a+1,s-1);
}
int main()
{
    char a[]={'1','2','3','\0'};
    char d[20];
    cin.getline(d,20);
    char_to_integer(d,strlen(d));
    cout<<endl;
    return 0;
} 


