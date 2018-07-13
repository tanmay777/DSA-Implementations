/**
 * Author: Tanmay Jha
 * Date: 08/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

void words(int n){
    if(n==0)
        return ;
    words(n/10);
    switch(n%10){
        case 1: cout<<"one ";
                break;
        case 2: cout<<"two ";
                break;
        case 3: cout<<"three ";
                break;
        case 4: cout<<"four ";
                break;
        case 5: cout<<"five ";
                break;
        case 6: cout<<"six ";
                break;
        case 7: cout<<"seven ";
                break;
        case 8: cout<<"eight ";
                break;
        case 9: cout<<"nine ";
                break;
        case 0: cout<<"zero ";
                break;
    }
}

int main()
{
    int n;
    cin>>n;
    int temp=n;
    words(n);
    cout<<endl;
    return 0;
} 


