/*
Given a MXN matrix, with some cells as blocked you have to-
1) find path from src to dest
2) count the no of paths from src to dest
3) print all possible paths
given the rat can only move forward and down.
*/

/**
 * Author: Tanmay Jha
 * Date: 12/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

void printSol(int soln[][10],int m,int n)
{
//This is printing the path.
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<soln[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
}

void ratInMazeWithOutBoolReturn(char maze[10][10],int soln[10][10],int i,int j,int m,int n){
    if(i==m&&j==n)
    {
        soln[i][j]=1;
        printSol(soln,m,n);
        soln[i][j]=0;
    }
    soln[i][j]=1;
    if(i+1<=n){
        if(maze[i+1][j]!='X')
            ratInMazeWithOutBoolReturn(maze,soln,i+1,j,m,n);
    }
    if(j+1<=m)
    {
        if(maze[i][j+1]!='X')
            ratInMazeWithOutBoolReturn(maze,soln,i,j+1,m,n);
    }
    soln[i][j]=0;
}
   

bool ratInMaze(char maze[10][10],int soln[10][10],int i,int j,int m,int n){

    if(i==m&&j==n)
    {
        soln[i][j]=1;
        printSol(soln,m,n);
	    return true;
    }
    
    if(i>m||j>n)
        return false;
            
    if(maze[i][j]=='X')
        return false;
    //Assuming solution exists through the current cell
    soln[i][j]=1;

    bool rightSuccess=ratInMaze(maze,soln,i,j+1,m,n);
    bool downSuccess=ratInMaze(maze,soln,i+1,j,m,n);

    soln[i][j]=0;

    if(rightSuccess||downSuccess)
        return true;

   return false;
}

int main()
{
    char maze[10][10]={
        "0000",
        "00X0",
        "000X",
        "0X00"};

    int soln[10][10]={0};

    int m=4,n=4;

    bool ans=ratInMaze(maze,soln,0,0,m-1,n-1);

    if(ans==false)
        cout<<"Path doesn't Exits"<<endl;

//    ratInMazeWithOutBoolReturn(maze,soln,0,0,m-1,n-1);
    cout<<endl;
    return 0;
} 


