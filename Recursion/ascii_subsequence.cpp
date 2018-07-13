/**
 * Author: Tanmay Jha
 * Date: 11/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

void generate_ascii_subsequence(char *arr,char *out,int i,int j){
    if(arr[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    out[j]=arr[i];
    generate_ascii_subsequence(arr,out,i+1,j+1);

    out[j]=48+(int)(arr[i]);
    generate_ascii_subsequence(arr,out,i+1,j+1);

    generate_ascii_subsequence(arr,out,i+1,j);

}

int main()
{
    char arr[100],out[100];
    cin>>arr;
    generate_ascii_subsequence(arr,out,0,0);
    cout<<endl;
    return 0;
} 


