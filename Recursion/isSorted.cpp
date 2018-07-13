/**
 * Author: Tanmay Jha
 * Date: 07/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

bool isSorted(int *a,int s){
    if(s==1)
        return true;
    else
        return ((a[0]<a[1]&&isSorted(a+1,s-1))?true:false);
}

int main()
{
    int arr[]={1,0,5,7,8};
    if(isSorted(arr,5))
        cout<<"Sorted"<<endl;
    else
        cout<<"Not Sorted"<<endl;
    return 0;
} 


