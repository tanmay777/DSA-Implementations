#include <iostream>
#define MAX 5

using namespace std;

void breathFirstSearch(int adj[][MAX],int visited[],int start);

int main()
{
    int visited[MAX]={0};
    int adj[MAX][MAX]={0,1,0,1,0,1,0,1,1,0,0,1,0,0,1,1,1,0,0,1,0,0,1,1,0},i,j;
    cout<<"Enter the adjacency matrix"<<endl;
    /*for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
            cin>>adj[i][j];*/
    cout<<"Input matrix is:\n";
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
    cout<<"BFS Path is: ";
    breathFirstSearch(adj,visited,0);
    return 0;
}

void breathFirstSearch(int adj[][MAX],int visited[], int start){
    int queue[MAX];
    int rear=-1,front=-1;
    queue[++rear]=start; //Our initial node is 0. From where we start traversing.
    visited[start]=1;    //To show that we have visited node 0
    while(rear!=front){
        start=queue[++front]; //We are printing the nodes as we go. See, front is pointing the nodes who have to be expanded. 
                              //As here we have moved front ahead. So, we will have neighbours of that node in next few lines of code
        cout<<(char)(start+65)<<" ";
        for(int i=0;i<MAX;i++)
        {
            if(adj[start][i]==1 && visited[i]==0){
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}
