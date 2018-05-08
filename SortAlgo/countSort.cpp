#include<iostream>
#include<string.h>

#define RANGE 255

using namespace std;

void countSort(char arr[]){
    int count[RANGE+1]={0}; //I don't know why the range has the +1 with it. 
    char output[strlen(arr)];

    for(int i=0;i<strlen(arr);++i){
        count[arr[i]]++;
    }

    for(int i=1;i<=RANGE;i++){
        count[i]+=count[i-1];
    }

    for(int i=strlen(arr);i>=0;i--){//Note: Here, the loop can go from either left to right or right to left. However, in radix sort, the loop can only go one way, i.e right to left
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }

    for(int i=0;i<strlen(arr);i++){
        arr[i]=output[i];
    }
}

int main(){
    char arr[]="tanmay";
    countSort(arr);
    cout<<"Sorted array is "<<arr<<endl;
    return 0;
}
