/**
 * Author: Tanmay Jha
 * Date: 28/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct Edge{
    int src,dest;
};

class Graph{
    public:
    vector<int> *adjList;

    Graph(vector<Edge> const &edges,int N)
    {
        adjList=new vector<int>[N];

        for(int i=0;i<edges.size();i++)
        {
            int src=edges[i].src;
            int dest=edges[i].dest;

            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }

    ~Graph(){
        delete[] adjList;
    }
};

void BFS(Graph const &graph,int v,vector<bool> &discovered){
    queue<int> q;
    discovered[v]=true;
    q.push(v);

    while(!q.empty()){
        v=q.front();
        q.pop();
        cout<<v<<" ";
        for(int u:graph.adjList[v]){
            if(!discovered[u])
            {
                discovered[u]=true;
                q.push(u);
            }
        }
    }
}


int main()
{
    vector<Edge> edges={{1,2},{1,3},{1,4},{2,5},{2,6},{5,9},{5,10},{4,7},{4,8},{7,11},{7,12}};
    //vertex 0,13,14 are single nodes
    int N=15;
    Graph graph(edges,N);
    vector<bool> discovered(N,false);

    for(int i=0;i<N;i++)
        if(discovered[i]==false)
            BFS(graph,i,discovered);
    //They are running the loop N times to account for isolated nodes also. 
    cout<<endl;
    return 0;
} 

