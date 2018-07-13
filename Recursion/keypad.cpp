/**
 * Author: Tanmay Jha
 * Date: 11/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;
char
X[10][5]={{'0','0','0','\0'},{'0','0','0','\0'},{'A','B','C','\0'},{'D','E','F','\0'},{'G','H','I','\0'},{'J','K','L','\0'},{'M','N','O','\0'},{'P','Q','R','S','\0'},{'T','U','V','\0'},{'W','X','Y','Z','\0'}};

void generate_strings(char *n,char out[10],int i,int j){
    if(n[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<",";
        return ;
    }
    else{
        int k=0;
        int digit=n[i]-'0';
        while(X[digit][k]!='\0'){
            out[j]=X[digit][k];
            generate_strings(n,out,i+1,j+1);
            k++;
        }
    }
}

int main()
{
    char n[10];
    cin>>n;
    char out[10];
    generate_strings(n,out,0,0);
    cout<<endl;
    return 0;
} 


