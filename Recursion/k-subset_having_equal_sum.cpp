/*
Array find k subset having equal sum
*/

/**
 * Author: Tanmay Jha
 * Date: 06/07/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int findSum(int out[],int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
        sum+=out[i];
    return sum;
}


void find_k_subset(int in[],int out[],int size,int i,int j,unordered_map<int,int> &presence){
    if(i==size)
    {
        int sum=findSum(out,j);

        if(presence.find(sum)==presence.end())
            presence.insert(pair<int,int>(sum,1));
        else
            presence[sum]++;

        return;
    }
    out[j]=in[i];
    find_k_subset(in,out,size,i+1,j+1,presence);
    find_k_subset(in,out,size,i+1,j,presence);
}

int main()
{
    int in[]={1,2,5,3,6,7};
    int out[6];
    int k;
    unordered_map<int,int>::iterator i;
    cin>>k;
    unordered_map<int,int> presence;
    find_k_subset(in,out,6,0,0,presence);
    for(i=presence.begin();i!=presence.end();i++)
    {
        if(i->second==k){
            cout<<"Sum is "<<i->first<<endl;
            cout<<"true\n";
cout<<"_______________$$$$\n";
cout<<"_____________$$____$$\n";
cout<<"_____________$$____$$\n";
cout<<"_____________$$____$$\n";
cout<<"_____________$$____$$\n";
cout<<"_____________$$____$$\n";
cout<<"_________$$$$$$____$$$$$$\n";
cout<<"_______$$____$$____$$____$$$$\n";
cout<<"_______$$____$$____$$____$$__$$\n";
cout<<"$$$$$__$$____$$____$$____$$____$$\n";
cout<<"$____$$$$________________$$____$$\n";
cout<<"$______$$______________________$$\n";
cout<<"_$$____$$______________________$$\n";
cout<<"__$$$__$$______________________$$\n";
cout<<"___$$__________________________$$\n";
cout<<"____$$$________________________$$\n";
cout<<"_____$$______________________$$$\n";
cout<<"______$$$____________________$$\n";
cout<<"_______$$____________________$$\n";
cout<<"________$$$________________$$$\n";
cout<<"_________$$________________$$\n";
cout<<"_________$$$$$$$$$$$$$$$$$$$$\n";
            break;
        }
    }
    if(i==presence.end())
     {       cout<<"false\n";
cout<<"_______________$$$$\n";
cout<<"_____________$$____$$\n";
cout<<"_____________$$____$$\n";
cout<<"_____________$$____$$\n";
cout<<"_____________$$____$$\n";
cout<<"_____________$$____$$\n";
cout<<"_________$$$$$$____$$$$$$\n";
cout<<"_______$$____$$____$$____$$$$\n";
cout<<"_______$$____$$____$$____$$__$$\n";
cout<<"$$$$$__$$____$$____$$____$$____$$\n";
cout<<"$____$$$$________________$$____$$\n";
cout<<"$______$$______________________$$\n";
cout<<"_$$____$$______________________$$\n";
cout<<"__$$$__$$______________________$$\n";
cout<<"___$$__________________________$$\n";
cout<<"____$$$________________________$$\n";
cout<<"_____$$______________________$$$\n";
cout<<"______$$$____________________$$\n";
cout<<"_______$$____________________$$\n";
cout<<"________$$$________________$$$\n";
cout<<"_________$$________________$$\n";
cout<<"_________$$$$$$$$$$$$$$$$$$$$\n";
}
    cout<<endl;
    return 0;
} 



