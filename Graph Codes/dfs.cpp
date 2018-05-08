#include <iostream>
#define MAX 5

using namespace std;

void depthFirstSearch(int adj[][MAX],int visited[],int start);

int main()
{
    int visited[MAX]={0};
    int adj[MAX][MAX]={0,1,0,1,0,1,0,1,1,0,0,1,0,0,1,1,1,0,0,1,0,0,1,1,0},i,j;
    /*cout<<"Enter the adjacency matrix"<<endl;
    for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
            cin>>adj[i][j];
    */cout<<"Input matrix is:\n";
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
    cout<<"DFS Path is: ";
    depthFirstSearch(adj,visited,0);
    return 0;
}

void depthFirstSearch(int adj[][MAX],int visited[], int start){
    int stack[MAX];
    int top=-1;
    stack[++top]=start;
    visited[start]=1;
    while(top!=-1){
        start=stack[top--];
        cout<<(char)(start+65);
        /*
            See, here we are choosing smaller node when given option. For eg. A is chosen when given A, D 
            as option for next node. However, its opposite in the book. They chose the larger node. So, as
            to make as book. replace the below loop as for(int i=0;i<MAX;i++). And you will get same answer 
            as that of book
        */
        for(int i=MAX-1;i>=0;i--){
            if(adj[start][i]&&(visited[i]==0)){
                stack[++top]=i;
                visited[i]=1;
            }
        }
        /*cout<<"Stack status is ";
        for(int i=0;i<=top;i++)
            cout<<(char)(stack[i]+65);
        cout<<endl;*/
    }
}
