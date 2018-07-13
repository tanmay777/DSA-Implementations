/* Given a string s, find all permutations of s*/

/**
 * Author: Tanmay Jha
 * Date: 11/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

void generate_permutations(char *in,int i){
    if(in[i]=='\0')
    {
        cout<<in<<",";
        return ;
    }
    for(int k=i;in[k]!='\0';k++)
    {
        swap(in[i],in[k]);
        generate_permutations(in,i+1);
        swap(in[i],in[k]);
    }
}

int main()
{
    char arr[10],out[10];
    cin>>arr;
    generate_permutations(arr,0);
    cout<<endl;
    return 0;
} 


