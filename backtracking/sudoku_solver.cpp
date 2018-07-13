/**
 * Author: Tanmay Jha
 * Date: 12/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;


bool CanPut(int arr[9][9],int row,int col,int size,int ele){

    //Checking for row and col
    for(int x=0;x<size;x++)
        if(arr[row][x]==ele||arr[x][col]==ele){
            return false;
        }
    //Checking the grid
    int n=sqrt(size);
    int sx=(row/n)*n;
    int sy=(col/n)*n;
    for(int x=sx;x<n+sx;x++){
        for(int y=sy;y<n+sy;y++){
            if(arr[x][y]==ele){
                return false;
            }
        }
    }
    return true;
}

void print_board(int arr[9][9],int size){
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

bool solveSudoko(int arr[9][9],int size,int i,int j)
{
    //Base Case
    if(i==size)
    {
        print_board(arr,size);
        return true;
    }
    if(j==size)
        return solveSudoko(arr,size,i+1,0);
    if(arr[i][j]!=0)
        return solveSudoko(arr,size,i,j+1);

    for(int number=1;number<=size;number++)
    {
        if(CanPut(arr,i,j,size,number)){
            arr[i][j]=number;
            bool wouldBeCorrect=solveSudoko(arr,size,i,j+1);
            if(wouldBeCorrect==true)
                return true;
        }
    }
    arr[i][j]=0;
    return false;
}
           

int main()
{
    /*int n;
    cin>>n;
    int arr[10][10]
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    */
    int arr[9][9]={
    5,3,0,0,7,0,0,0,0,
    6,0,0,1,9,5,0,0,0,
    0,9,8,0,0,0,0,6,0,
    8,0,0,0,6,0,0,0,3,
    4,0,0,8,0,3,0,0,1,
    7,0,0,0,2,0,0,0,6,
    0,6,0,0,0,0,2,8,0,
    0,0,0,4,1,9,0,0,5,
    0,0,0,0,8,0,0,7,9};

    solveSudoko(arr,9,0,0);
    cout<<endl;
    return 0;
} 

