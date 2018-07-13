/*Efficient Cost

You will be given an integer array and a threshold value. The threshold represents the maximum length of subarrays that may be created for the challenge. Each sub-aray you create
has a cost equal to maximum integer within the sub-array. Your challenge is to partition the entire array into sub-arrays no longer than the threshold, and do it at minimum cost

Input : 1 5 2   k=2
Output : 6

Input : 1 5 5 1  k=2
Output : 7
*/

/**
 * Author: Tanmay Jha
 * Date: 09/07/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

void calculateMinCost(vector<int> &x){
    for(int size=1;i<x.size();i++){
        for(int j=0;j<x.size();j+=size);
        {
            for(int k=j;k<j+size;j++){
                cout<<arr[i]<<" "
                }
                cout<<" ,";
        }
    }
}

int main()
{
    int arr[]={1,5,5,1};
    vector<int> x(arr,arr+4);
    calculateMinCost(x);
    cout<<endl;
    return 0;
} 


