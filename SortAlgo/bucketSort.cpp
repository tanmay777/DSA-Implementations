#include<iostream>
#include<vector>

using namespace std;

void bucketSort(float arr[],int n){
    
    vector<float> b[n];
    int newNum,i,index=0;
    
    for(i=0;i<n;i++){
        newNum=arr[i]*n;
        b[newNum].push_back(arr[i]);
    }

    for(i=0;i<n;i++){
        sort(b[i].begin(),b[i].end());
    }

    for(i=0;i<n;i++)
        for(int j=0;j<b[i].size();j++)
            arr[index++]=b[i][j];

}

int main()
{
    float arr[]={0.54,0.49,0.67,0.64,0.12,0.11};
    cout<<"Inserted array ";
    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    bucketSort(arr,(sizeof(arr)/sizeof(arr[0])));
    cout<<"Output array ";
    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
