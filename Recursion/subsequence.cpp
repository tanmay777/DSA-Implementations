/**
 * Author: Tanmay Jha
 * Date: 10/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

void generate_subsequence(char word[20],char out[20],int i,int j)
{
    if(word[i]=='\0'){
        out[j]='\0';
        cout<<out<<",";
        return;
    }
    out[j]=word[i];
    generate_subsequence(word,out,i+1,j+1);   
    generate_subsequence(word,out,i+1,j);
}

int main()
{
    char arr[20],out[20];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr;
        generate_subsequence(arr,out,0,0);
        cout<<endl;
    }
    cout<<endl;
    return 0;
} 


