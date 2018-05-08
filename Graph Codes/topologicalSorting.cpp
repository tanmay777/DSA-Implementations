#include<iostream>
#define MAX 7

using namespace std;

int n=7,adj[7][7]={0,1,0,0,0,0,0,
    0,0,1,1,1,0,0,
    0,0,0,0,1,0,0,
    0,0,0,0,1,0,0,
    0,0,0,0,0,1,0,
    0,0,0,0,0,0,0,
    0,0,0,1,0,0,0};
int front=-1,rear=-1,queue[MAX];

void createGraph();
void display();
void insert_queue(int);
int delete_queue();
int find_indegree(int);

int main(){
    int node,j=0,del_node;
    int topSort[MAX],indeg[MAX];
    createGraph();
    cout<<"The adjacency matrix is";
    display();
    for(node=0;node<n;node++){
        indeg[node]=find_indegree(node);
        if(find_indegree(node)==0)
            insert_queue(node);
    }
    while(front<=rear)
    {
        del_node=delete_queue();
        topSort[j]=del_node;
        j++;
        for(node=0;node<n;node++){
            if(adj[del_node][node]==1){
                adj[del_node][node]=0;
                indeg[node]-=1;
                if(indeg[node]==0)
                    insert_queue(node);
            }
        }
    }
    cout<<"Topological Sorting can be given as: ";
    for(node=0;node<j;node++)
        cout<<topSort[node];
    
    return 0;
}

void createGraph(){
    
    /*int i,orig,dest,max_edges;
    cout<<"Enter the number of vertices ";
    cin>>n;
    max_edges=n*(n-1);
    for(i=0;i<max_edges;i++){
        cout<<"Enter the orig and dest for edge number "<<i<<endl;
        cin>>orig>>dest;
        if(orig==0&&dest==0)
            break;
        else if(orig<0||dest<0||orig>n||dest>n)
            cout<<"Invalid orig and destination";
        else
            adj[orig][dest]=1;
    }*/
}

void display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
     cout<<endl;
     }
}

void insert_queue(int node){
    if(rear==n-1)
        cout<<"OVERFLOW";
    else if(front==-1)
        front=0;
    queue[++rear]=node;
}

int delete_queue(){
    if(front==-1||front>rear)
    {
        cout<<"UNDERFLOW!";
        return 0; 
    }
    else
        return queue[front++];
}

int find_indegree(int node){
    int count;
    for(int i=0;i<n;i++)
    {
        if(adj[i][node]==1)
            count++;
    }
    return count;
}
