/**
 * Author: Tanmay Jha
 * Date: 11/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

bool isSafe(int board[][10],int row,int col,int n){
    //Checking the column
    for(int i=0;i<row;i++)
        if(board[i][col]==1)
            return false;

    //Checking for left diagonal
    int x=row;
    int y=col;
    while(x>=0&&y>=0){
        if(board[x][y]==1)
            return false;
        x--;
        y--;
    }
    //Checking for right diagonal
    x=row;
    y=col;
    while(x>=0&&y<n){
        if(board[x][y]==1)
            return false;
        x--;
        y++;
    }
    return true;
}

void printBoard(int board[][10],int n){
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                if(board[i][j]==1)
                    cout<<"Q ";
                else
                    cout<<"_ ";
            }
            cout<<endl;
        }
}

bool solveNQueens(int board[][10],int i,int n){

    //Base Case
    if(i==n)
    {
        printBoard(board,n);
        cout<<endl;
        return false;//Ideally this should be true but we are faking a false. So, that it gives other possible queen
        //combinations also. 
    }

    //Recursive Case
    for(int j=0;j<n;j++)
    {

        if(isSafe(board,i,j,n)){
            board[i][j]=1;
            bool isSafeInFuture=solveNQueens(board,i+1,n);
            if(isSafeInFuture)
                return true;
            board[i][j]=0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int board[10][10]={0};
    solveNQueens(board,0,n);
    cout<<endl;
    return 0;
} 


