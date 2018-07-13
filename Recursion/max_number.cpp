/* You have to make maximum number by removing any k elements from the given number */

/**
 * Author: Tanmay Jha
 * Date: 06/07/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>
#include<string.h>

using namespace std;

int val(char *out){
    int sum=0;int prod=1;
    int n=strlen(out)-1;
    int res=1;
    for(int k=0;k<strlen(out);k++)
    {
        res=0;
        prod=1;
        res+=out[k]-'0';
        int temp=n;
        while(temp!=0){
            prod*=10;
            temp--;
        }
        res*=prod;
        n--;
        sum+=res;
    }
    return sum;
}

int max_number(char *in,char *out,int i,int j,int k){
    int number_1,number_2;
    if(k!=0&&in[i]=='\0')
        return 0;
    if(k==0&&in[i]=='\0')
    {
        out[j]='\0';       
        return val(out);
    }

    out[j]=in[i];
    number_1=max_number(in,out,i+1,j+1,k);
    
    if(k!=0){
        number_2=max_number(in,out,i+1,j,k-1);
    }

    return max(number_1,number_2);
}

int main()
{
    char in[10];
    cin.getline(in,sizeof(in));
    int n;
    cin>>n;
    char out[10];
    cout<<max_number(in,out,0,0,n);
    cout<<endl;
    return 0;
} 


